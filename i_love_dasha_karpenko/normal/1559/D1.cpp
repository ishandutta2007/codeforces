//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e3+7;
int P[2][N];
int F(int g,int x){
    if (P[g][x]==x)
        return x;
    return P[g][x] = F(g,P[g][x]);
}
void unite(int g,int a,int b){
    a = F(g,a);
    b = F(g,b);
    P[g][a] = b;
}
int check(int a,int b){
    return F(0,a)!=F(0,b) && F(1,a)!=F(1,b);
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        P[0][i] = P[1][i] = i;
    int m1,m2;
    cin>>m1>>m2;
    for(int i = 1;i<=m1;++i){
        int u,v;
        cin>>u>>v;
        unite(0,u,v);
    }
    for(int i = 1;i<=m2;++i){
        int u,v;
        cin>>u>>v;
        unite(1,u,v);
    }
    vector<pair<int,int> > ans;
    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            if (check(i,j)){
                unite(0,i,j);
                unite(1,i,j);
                ans.push_back({i,j});
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto [a,b]:ans)
        cout<<a<<' '<<b<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    //cin>>t;
    t = 1;
    while(t--)
        solve();
    return 0;
}