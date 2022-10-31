#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e5+7;
int A[N],total = 0,cnt = 0;
vector<int> G[N];
void dfs(int v,int par){
    for(int to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
        A[v]^=A[to];
    }
    if (A[v]==total)
        ++cnt,A[v] = 0;
}
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        total^=A[i];
    }
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    if (total==0 || (k>2 && cnt>=3)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    for(int i = 1;i<=n;++i)
        G[i].clear();
    cnt = total = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}