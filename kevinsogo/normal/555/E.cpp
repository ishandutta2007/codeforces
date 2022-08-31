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

#define LIM 400111
vector< vector<int> > adj(LIM);
vector< vector<int> > bridges(LIM);
vector< set<int> > sbridges(LIM);
vector< vector<int> > badj(LIM);
bool vis[LIM];
int disc[LIM];
int low[LIM];
int comp[LIM];
int parent[LIM];
int goods[LIM];
int tm = 0;
int cp;
void find_bridges(int i) {
    // pf("%d: %d\n", i, cp);
    goods[cp] = i;
    comp[i] = cp;
    vis[i] = true;
    disc[i] = low[i] = ++tm;
    for (int nb = 0; nb < adj[i].size(); nb++) {
        int j = adj[i][nb];
        if (!vis[j]) {
            parent[j] = i;
            find_bridges(j);
            low[i] = min(low[i], low[j]);
            if (low[j] > disc[i]) {
                bridges[i].push_back(j);
                bridges[j].push_back(i);
                sbridges[i].insert(j);
                sbridges[j].insert(i);
            }
        } else if (j != parent[i]) {
            low[i] = min(low[i], low[j]);
        }
    }
}
int as[LIM];
int bs[LIM];
int queue[LIM];

int size[LIM];
int hson[LIM];
int hpath[LIM];
int hindex[LIM];

int depth[LIM];

bool good;
struct segtree {
    int i, j;
    int value;
    int setvalue;
    segtree *l, *r;
    segtree(int i, int j): i(i), j(j) {
        value = 0;
        setvalue = 0;
        if (j - i == 1) {
            l = r = NULL;
        } else {
            int k = i + j >> 1;
            l = new segtree(i, k);
            r = new segtree(k, j);
        }
    }
    void visit() {
        if (setvalue) {
            value |= setvalue;
            if (l) {
                l->setvalue |= setvalue;
                r->setvalue |= setvalue;
            }
            setvalue = 0;
        }
    }
    void mask(int I, int J, int v) {
        if (I <= i && j <= J) {
            setvalue |= v;
            visit();
        } else {
            visit();
            if (!(j <= I || J <= i)) {
                l->mask(I, J, v);
                r->mask(I, J, v);
            }
        }
    }
    bool any() {
        visit();
        // pf("value %d %d: %d\n", i, j, value);
        if (j - i == 1) {
            return value == 3;
        } else {
            return l->any() || r->any();
        }
    }

};

int hsize[LIM];
int hparent[LIM];
segtree *trees[LIM];
void init(int i) {
    trees[i] = new segtree(0, hsize[i]);
}
void computes(int i, int cp) {
    comp[i] = cp;
    fr(nb,adj[i].size()) {
        int j = adj[i][nb];
        if (comp[j] != -1) continue;
        if (sbridges[i].find(j) != sbridges[i].end()) continue;
        computes(j, cp);
    }
}
int main() {
    int n, m, qq;
    sf("%d%d%d", &n, &m, &qq);
    fr(i,m) {
        int a, b;
        sf("%d%d", &a, &b);
        a--,b--;
        adj[a].push_back(n);
        adj[n].push_back(a);
        adj[b].push_back(n);
        adj[n].push_back(b);
        n++;
    }
    cp = 0;
    fr(i,n) {
        if (!vis[i]) {
            find_bridges(i);
           cp++;
        }
    }
    good = true;
    fr(i,qq) {
        sf("%d%d", as + i,bs + i);
        as[i]--,bs[i]--;
        if (comp[as[i]] != comp[bs[i]]) {
            // pf("%d %d\n", as[i], bs[i]);
            good = false;
        }
    }
    if (good) {
        fo(i,1,cp) {
            int a = goods[i-1];
            int b = goods[i];
            bridges[a].push_back(b);
            bridges[b].push_back(a);
            sbridges[a].insert(b);
            sbridges[b].insert(a);
        }
        fr(i,n) {
            fr(nb,bridges[i].size()) {
                int j = bridges[i][nb];
                // pf("bri %d %d\n", i, j);
            }
        }
        cp = 0;
        fr(i,n) comp[i] = -1;
        fr(i,n) {
            if (comp[i] == -1) {
                computes(i,cp);
                cp++;
            }
        }
        fr(i,n) {
            int ci = comp[i];
            fr(nb,bridges[i].size()) {
                int cj = comp[bridges[i][nb]];
                if (ci != cj) {
                    badj[ci].push_back(cj);
                    badj[cj].push_back(ci);
                }
            }
        }
        int q = 1;
        queue[0] = 0;
        fr(i,cp) vis[i] = false;
        vis[0] = true;
        fr(f,q) {
            int i = queue[f];
            fr(nb,badj[i].size()) {
                int j = badj[i][nb];
                // pf("%d -> %d\n", i, j);
                if (!vis[j]) {
                    vis[j] = true;
                    parent[j] = i;
                    queue[q++] = j;
                }
            }
        }

        fr(i,q) {
            size[i] = 1;
            hson[i] = -1;
            hpath[i] = -1;
        }
        ffo(f,1,q) {
            int i = queue[f];
            int p = parent[i];
            size[p] += size[i];
            if (hson[p] == -1 || size[hson[p]] < size[i]) hson[p] = i;
        }
        int pathc = 0;
        fr(f,q) {
            int i = queue[f];
            if (hpath[i] == -1) {
                hsize[pathc] = 0;
                hpath[i] = pathc++;
            }
            int s = hson[i];
            if (s != -1) {
                hpath[s] = hpath[i];
            }
            hsize[hpath[i]]++;
        }
        hindex[0] = 0;
        fo(f,1,q) {
            int i = queue[f];
            int p = parent[i];
            if (hpath[p] != hpath[i]) {
                depth[hpath[i]] = depth[hpath[p]] + 1;
                hparent[hpath[i]] = p;
                hindex[i] = 0;
            } else {
                hindex[i] = hindex[p] + 1;
            }
        }
        fr(i,pathc) {
            init(i);
        }
        fr(i,qq) {
            int a = comp[as[i]];
            int b = comp[bs[i]];
            // pf("%d %d\n", a, b);
            while (hpath[a] != hpath[b]) {
                if (depth[hpath[a]] > depth[hpath[b]]) {
                    trees[hpath[a]]->mask(0, hindex[a]+1, 1);
                    a = hparent[hpath[a]];
                } else {
                    trees[hpath[b]]->mask(0, hindex[b]+1, 2);
                    b = hparent[hpath[b]];
                }
            }
            if (hindex[a] > hindex[b]) {
                trees[hpath[a]]->mask(hindex[b]+1, hindex[a]+1, 1);
            } else if (hindex[b] > hindex[a]) {
                trees[hpath[a]]->mask(hindex[a]+1, hindex[b]+1, 2);
            }
        }
        fr(i,pathc) {
            if (trees[i]->any()) {
                good = false;
                break;
            }
        }
    }
    pf(good ? "Yes\n" : "No\n");

}