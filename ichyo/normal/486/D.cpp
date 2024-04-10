#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef vector<int> Node;
typedef vector<Node> Graph;
int D, N;
int A[2020];
Graph G;
typedef long long LL;
const int MOD = 1000000007;
LL dfs(int u, int p, pair<int, int> root){
    vector<LL> vs;
    for(int v : G[u]) if(v != p) {
        if(make_pair(A[v], v) > root && A[v] <= root.first + D) {
            vs.push_back(dfs(v, u, root) + 1);
        }
    }
    LL res = 1;
    for(LL x : vs) res = (res * x) % MOD;
    return res;
}

int main(){
    while(cin >> D >> N) {
        G.clear();
        G.resize(N);
        REP(i, N) cin >> A[i];
        REP(i, N-1) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        LL ans = 0;
        REP(i, N){
            ans += dfs(i, -1, make_pair(A[i], i));
            ans %= MOD;
        }

        cout << ans << endl;
    }
    return 0;
}