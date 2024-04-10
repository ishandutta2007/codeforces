//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+7;
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
    for(int i = 2;i<=n;++i){
        if (check(1,i))
            unite(0,1,i),unite(1,1,i),ans.push_back({1,i});
    }
    vector<int> v1,v2;
    for(int i = 2;i<=n;++i){
        if (F(0,i)==F(0,1) && F(1,i)!=F(1,1))
            v1.push_back(i);
        if (F(0,i)!=F(0,1) && F(1,i)==F(1,1))
            v2.push_back(i);
        while(!v1.empty() && F(1,v1.back())==F(1,1))
            v1.pop_back();
        while(!v2.empty() && F(0,v2.back())==F(0,1))
            v2.pop_back();
        if (!v1.empty() && !v2.empty()){
            unite(0,v1.back(),v2.back());
            unite(1,v1.back(),v2.back());
            ans.push_back({v1.back(),v2.back()});
            v1.pop_back();
            v2.pop_back();
            //break;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto [a,b]:ans){
        cout<<a<<' '<<b<<'\n';
    }
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