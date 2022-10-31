#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
int A[N];
ll dp[N];
vector<int> G[N];
void solve(){
    int n;
    cin>>n;
    queue<int> Q;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        for(int j = 0;j<A[i];++j){
            int x;
            cin>>x;
            G[x].push_back(i);
        }
        if (A[i]==0){
            dp[i] = i;
            Q.push(i);
        }
    }
    int cnt = 0;
    ll res = 0;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        res = max(res,dp[v]);
        ++cnt;
        for(int to:G[v]){
            A[to]--;
            dp[to] = max(dp[to],dp[v]+(to-v+n)%n);
            if (A[to]==0)
                Q.push(to);
        }
    }
    if (cnt<n){
        cout<<"-1\n";
    }
    else{
        cout<<res/n+(res%n!=0)<<endl;
    }
    for(int i = 1;i<=n;++i){
        A[i] = dp[i] = 0;
        G[i].clear();
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}