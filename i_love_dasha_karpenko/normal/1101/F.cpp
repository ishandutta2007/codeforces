//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gt(tuple,el) (get<el>(tuple))
const int N = 4e2+7;
const int INF = 1e9+1e5;
const int M = 25e4+7;
int A[N],dp[2][N][N],vis[N];
vector<tuple<int,int,int> > Q[N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }

    for(int i = 1;i<=m;++i){
        int st,fi,c,r;
        cin>>st>>fi>>c>>r;
        Q[r].push_back({st,fi,c});
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j)
            dp[0][i][j] = INF;
        dp[0][i][i] = 0;
    }
    ll res = 0;
    for(int r = 0;r<=n;++r){
        for(int a = 1;a<=n;++a){
            int mx = 0;
            for(int i = 1;i<=n;++i)
                vis[i] = 0;
            queue<pair<int,int>> Q,over;
            for(int b = a;b<=n;++b){
                Q.push({dp[0][a][b],b});
                if (dp[0][a][b]+A[b]<=A[n])
                    over.push({dp[0][a][b]+A[b],b});
                while(!over.empty() && over.front().first<=A[b]){
                    vis[over.front().second] = 1;
                    mx = max(mx,A[over.front().second]);
                    over.pop();
                }
                while(!Q.empty() && vis[Q.front().second]==1)
                    Q.pop();
                dp[1][a][b] = A[b]-mx;
                if (!Q.empty())
                    dp[1][a][b] = min(dp[1][a][b],Q.front().first);
            }
        }
        for(auto to:Q[r]){
            res = max(res,ll(dp[1][gt(to,0)][gt(to,1)])*gt(to,2));
        }
        swap(dp[1],dp[0]);
    }
    cout<<res<<endl;
    return 0;
}