//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E6+7;

int P[N],cnt[N],total = 0;
int F(int x){
    return x==P[x]?x:P[x] = F(P[x]);
}
int unite(int a,int b){
    if (P[a]==0)
        ++total,P[a] = a;
    if (P[b]==0)
        ++total,P[b] = b;
    a = F(a);
    b = F(b);
    if (a==b)
        return 0;
    P[a] = b;
    return 1;
}
void solve(){
    int n,m;
    cin>>n>>m;

    int res = 0,ptl = 0;
    for(int i = 1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        if (u==v){
            ++ptl;
            if (P[u]==0){
                P[u] = u;
                ++total;
            }
            continue;
        }
        res+=unite(u,v);
        ++cnt[u];
        ++cnt[v];
    }
    if (res!=total-1 || m==1)
        cout<<"0\n";
    else {
        ll res = 0;
        for(int i = 1;i<=n;++i){
            res+=ll(cnt[i])*(cnt[i]-1)/2;
        }
        res+=ll(m-ptl)*ptl;
        res+=ll(ptl)*(ptl-1)/2;
        cout<<res<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}