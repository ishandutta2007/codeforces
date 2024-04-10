#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
const int N = 2e5+7;
vector<int> G[N];
ll L[N],R[N];
ll A[N],res;
void dfs(int v){
    ll sum = 0;
    for(int to:G[v]){
        dfs(to);
        sum += A[to];
    }
    if (sum>=L[v]){
        A[v] = min(R[v],sum);
    }
    else{
        A[v] = R[v];
        res += 1;
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        G[i].clear();
    }
    for(int i = 2;i<=n;i+=1){
        int par; cin>>par;
        G[par].push_back(i);
    }
    for(int i = 1;i<=n;i+=1){
        cin>>L[i]>>R[i];
    }
    res = 0;
    dfs(1);
    cout<<res<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}