#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int a[1111];
int b[1111];

struct edge {
    int a, b;
    int flow;
    int cap;
    edge *pair;

    edge(int a, int b, int cap): a(a), b(b), cap(cap) {
        flow = 0;
    }
    int nxt(int x) {
        return x == a ? b : a;
    }
};

int N, S, T, E;
vector< vector<edge*> > adj(111111);
void add_edge(int a, int b, int cap) {
    edge *ab = new edge(a, b, cap);
    edge *ba = new edge(b, a, 0);
    ab->pair = ba;
    ba->pair = ab;
    adj[a].push_back(ab);
    adj[b].push_back(ba);
}

int qs[111111];
edge *pt[111111];
edge *blank = new edge(-1, -1, -1);
int res[511][511];


bool aug() {
    fr(i,N) pt[i] = NULL;
    pt[S] = blank;
    int q = 1;
    qs[0] = S;
    fr(f,q) {
        int i = qs[f];
        fr(nb,adj[i].size()) {
            edge *e = adj[i][nb];
            if (e->flow < e->cap) {
                int j = e->nxt(i);
                if (!pt[j]) {
                    pt[j] = e;
                    qs[q++] = j;
                    if (j == T) return true;
                }
            }
        }
    }
    return false;
}

#define inf (1<<30)

int main() {
    int n, e;
    sf("%d%d", &n, &e);
    fr(i,n) sf("%d", a +i );
    fr(i,n) sf("%d", b +i );
    int ttl = 0, tt2 = 0;
    fr(i,n) ttl += a[i];
    fr(i,n) tt2 += b[i];
    ttl = max(ttl, tt2);
    N = 2*n+2;
    S = 2*n;
    T = 2*n+1;
    // 0..n-1, n..2*n-1, 2*n, 2*n+1
    E = 0;
    fr(i,n) {
        add_edge(i, n+i, inf);//min(a[i], b[i]));
        add_edge(S, i, a[i]);
        add_edge(n+i, T, b[i]);
    }
    fr(i,e) {
        int x, y;
        sf("%d%d", &x, &y);
        if (x == y) continue;
        x--, y--;
        add_edge(x, n+y, inf);//min(a[x], b[y]));
        add_edge(y, n+x, inf);//min(a[y], b[x]));
    }


    int flow = 0;
    while (aug()) {
        int ex = inf;
        for (int curr = T; curr != S;) {
            edge *e = pt[curr];
            ex = min(ex, e->cap - e->flow);
            curr = e->nxt(curr);
        }
        flow += ex;
        for (int curr = T; curr != S;) {
            edge *e = pt[curr];
            e->flow += ex;
            e->pair->flow -= ex;
            curr = e->nxt(curr);
        }
    }
    if (flow != ttl) {
        pf("NO\n");
    } else {
        pf("YES\n");
        fr(i,n) {
            fr(j,n) res[i][j] = 0;
            fr(nb,adj[i].size()) {
                edge *e = adj[i][nb];
                int j = e->nxt(i);
                if (n <= j && j < 2*n) {
                    j -= n;
                    if (e->flow > 0) {
                        res[i][j] += e->flow;
                    }
                }
            }
            fr(j,n) {
                if (j) pf(" ");
                pf("%d", res[i][j]);
            }
            pln;
        }
    }
}