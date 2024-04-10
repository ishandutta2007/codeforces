// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

typedef vector<int> Node;
typedef vector<Node> Graph;
bool is_leaf[200010];
Graph G;
int dfs(int u, int p, int turn) {
    if(is_leaf[u]) {
        return 1;
    } else {
        if(turn == 0) {
            int res = INT_MAX;
            REP(i, G[u].size()) if(G[u][i] != p) {
                int c = G[u][i];
                res = min(res, dfs(c, u, 1));
            }
            return res;
        } else {
            int res = 0;
            REP(i, G[u].size()) if(G[u][i] != p) {
                int c = G[u][i];
                res += dfs(c, u, 0);
            }
            return res;
        }
    }
}
int LEAF;
int child;
void calc(int u, int p) {
    child = 0;
    REP(i, G[u].size()) if(G[u][i] != p) child++;

    if(child == 0) {
        is_leaf[u] = true;
        LEAF++;
    } else {
        REP(i, G[u].size()) if(G[u][i] != p) {
            calc(G[u][i], u);
        }
    }
}

int main(){
    iostream_init();
    int n;
    while(cin >> n) {
        memset(is_leaf, 0, sizeof(is_leaf));
        G.assign(n, Node());
        REP(i, n-1) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        LEAF = 0;
        calc(0, -1);

        // cout << "LEAF: " << LEAF << endl;
        int A = LEAF - (dfs(0, -1, 0) - 1);
        int B = dfs(0, -1, 1);
        cout << A << " " << B << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */