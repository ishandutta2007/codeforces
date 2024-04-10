#include <bits/stdc++.h>
using namespace std;

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
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)

typedef long long ll;
const int N = 411111;

vector<int> adj[N];
int parent[N];
bool cbefore[N];
bool cafter[N];
bool killed[N];
void kill(int i, bool killp) {
    if (killp) {
        assert(cafter[i]);
    } else {
        assert(cbefore[i]);
    }
    int deg = killp ? 0 : 1;
    for (int j : adj[i]) {
        if (j == parent[i]) continue;
        if (cbefore[j]) {
            kill(j, false);
        } else {
            deg++;
        }
    }
    pf("%d\n", i + 1);
    assert(deg % 2 == 0);
    assert(!killed[i]);
    killed[i] = true;
    for (int j : adj[i]) {
        if (j == parent[i]) continue;
        if (!killed[j]) {
            assert(cafter[j]);
            kill(j, true);
        }
    }
}
int main() {
    int n;
    sf("%d", &n);
    fr(i,n) {
        int j;
        sf("%d", &j);
        if (--j >= 0) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        parent[i] = -1;
    }
    vector<int> que;
    que.push_back(0);
    parent[0] = 0;
    fr(f,que.size()) {
        int i = que[f];
        // pf("at %d\n", i+1);
        for (int j : adj[i]) {
            if (parent[j] == -1) {
                parent[j] = i;
                que.push_back(j);
            }
        }
    }
    ffr(f,que.size()) {
        int i = que[f];
        int deg = 0;
        for (int j : adj[i]) {
            if (j == parent[i]) continue;
            // pf("%d -> %d\n", 1+i, 1+j);
            if (cbefore[j] && cafter[j]) {
                deg = -1;
                break;
            } else if (!cbefore[j] && !cafter[j]) {
                deg = -2;
                break;
            } else if (cafter[j]) {
                deg++;
            } else {
                assert(cbefore[j]);
            }
        }
        cbefore[i] = cafter[i] = false;
        if (deg == -1) {
            cbefore[i] = cafter[i] = true;
        } else if (deg != -2) {
            if (deg & 1) {
                cbefore[i] = true;
            } else {
                cafter[i] = true;
            }
        }
        // pf("doing %d, deg = %d, bef=%d, aft=%d\n", i + 1, deg, cbefore[i], cafter[i]);
    }
    if (cafter[0]) {
        puts("YES");
        kill(0, true);
    } else {
        puts("NO");
    }
}