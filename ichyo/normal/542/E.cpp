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
int group[1010];
int answer[1010];
Graph G;
void dfs(int u, int id) {
    if(group[u] != -1) return;
    group[u] = id;
    for(int v : G[u]) {
        dfs(v, id);
    }
}
int level[1010];
int bfs(int s) {
    queue<int> que;
    memset(level, -1, sizeof(level));
    level[s] = 0;
    que.push(s);
    int res = 0;
    while(!que.empty()) {
        int u = que.front(); que.pop();
        //REP(i, G.size()) dump(level[i]);
        res = max(res, level[u]);
        for(int v : G[u]) {
            if(level[v] == -1) {
                level[v] = level[u] + 1;
                que.push(v);
            } else if(abs(level[v] - level[u]) == 1) {
            } else {
                return INT_MIN;
            }
        }
    }
    // dump(res);
    return res;
}
int main(){
    iostream_init();
    int n, m;
    while(cin >> n >> m) {
        memset(group, -1, sizeof(group));
        G.assign(n, Node());

        REP(i, m) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int ID = 0;
        REP(i, n) if(group[i] == -1) {
            dfs(i, ID++);
        }
        REP(i, ID) answer[i] = INT_MIN;
        REP(i, n) {
            int g = group[i];
            assert(g != -1);
            answer[g] = max(answer[g], bfs(i));
        }
        int ans = 0;
        REP(i, ID){
            if(answer[i] == INT_MIN) {
                ans = -1;
                break;
            }
            ans += answer[i];
        }
        cout << ans << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */