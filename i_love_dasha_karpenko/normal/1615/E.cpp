#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')

const int N = 2e5+7;

vector<int> G[N];
int P[N],depth[N],dp[N];
void dfs(int v,int par){
    depth[v] = depth[par]+1;
    P[v] = par;
    dp[v] = v;
    for(int to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
        if (depth[dp[to]]>depth[dp[v]])
            dp[v] = dp[to];
    }
}
priority_queue<pair<int,int> > Q;
void add(int v,int nto){
    for(int to:G[v]){
        if (to==P[v] || to==nto)
            continue;
        Q.push({depth[dp[to]]-depth[to]+1,to});
    }
}
void solve() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;++i)
        G[i].clear();
    while(!Q.empty())
        Q.pop();
    for(int i = 1;i<n;++i){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int leaves = 0;
    for(int i = 2;i<=n;++i){
        if (G[i].size()==1)
            ++leaves;
    }
    if (leaves<=k){
        ll res = 0;
        for(int i = leaves;i<=k;++i)
            res = max(res,ll(i)*(n-i));
        cout<<res<<endl;
        return;
    }
    dfs(1,1);
    int blue = n;

    Q.push(mp(depth[dp[1]]-depth[1]+1,1));
    int bk = k;
    while(!Q.empty() && bk){
        --bk;
        blue-=Q.top().first;
        int v = Q.top().second;
        Q.pop();
        int vert = dp[v];
        int prev = vert;
        while(1){
            add(vert,prev);
            prev = vert;
            if (v==vert)
                break;
            vert = P[vert];
        }
    }

    ll res = ll(n)*n;
    for(int bl = 0;bl<=blue;++bl){
        int red = k-bk;
        int w = n-red-bl;
        res = min(res,ll(red-bl)*w);
    }
    cout<<res<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;

    while(t--)
        solve();
}