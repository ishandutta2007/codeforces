#include <bits/stdc++.h>
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
using namespace std;

#define N 611111
#define E (2*N)

typedef pair<int,int> edge;
vector<edge> adj[N];

bool take[E];
bool ntake[N];
bool vis[N];
int targ[N];
int n, e;
int parent[N];
int parente[N];

bool solve_comp(int i) {
    vector<int> que;
    vis[i] = true;
    que.push_back(i);
    int salo = -1;
    vector<int> odds;
    int root = i;
    parent[root] = root;
    for (int f = 0; f < que.size(); f++) {
        i = que[f];
        if (targ[i] == -1) {
            salo = i;
        } else if (targ[i] == 1) {
            odds.push_back(i);
        }
        for (auto nb : adj[i]) {
            int j = nb.first;
            int idx = nb.second;
            if (!vis[j]) {
                vis[j] = true;
                parent[j] = i;
                parente[j] = idx;
                que.push_back(j);
            }
        }
    }

    if (odds.size() & 1) {
        if (~salo) {
            odds.push_back(salo);
        } else {
            return false;
        }
    }
    assert(!(odds.size() & 1));
    for (int j : odds) {
        ntake[j] = true;
    }
    for (int f = que.size(); f--;) {
        int j = que[f];
        if (ntake[j]) {
            take[parente[j]] = true;
            ntake[parent[j]] ^= true;
        }
    }

    return true;
}

bool solve() {
    for (int i = 0; i < e; i++) {
        take[i] = false;
    }
    for (int i = 0; i < n; i++) {
        vis[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (!solve_comp(i)) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &e);
    for (int i = 0; i < n; i++) {
        scanf("%d", &targ[i]);
    }
    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    if (solve()) {
        vector<int> ans;
        for (int i = 0; i < e; i++) if (take[i]) ans.push_back(i);
        printf("%d\n", int(ans.size()));
        for (int i = 0; i < ans.size(); i++) {
            printf("%d%c", ans[i] + 1, " \n"[i == ans.size() - 1]);
        }
    } else {
        printf("-1\n");
    }
}