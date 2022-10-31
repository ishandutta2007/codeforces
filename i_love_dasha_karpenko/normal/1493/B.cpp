//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 100+7;
const ll INF = 1E9;
pair<ll,ll> ans[DIM][DIM];
ll Ch(ll x){
    if (x==0 || x==1 || x==8)
        return x;
    if (x==2)
        return 5;
    if (x==5)
        return 2;
    return INF;
}
ll trans(ll x){
    ll d1 = x%10;
    ll d2 = x/10;
    if (Ch(d1)==INF && Ch(d2)==INF)return INF;
    d1 = Ch(d1);
    d2 = Ch(d2);
    return d1*10+d2;
}
void solve(){
    ll t = 1;

    ll h,m;
    cin>>h>>m;
    ll res = 0;
    pair<ll,ll> last = {0,0};
    for(ll a = h-1;a>=0;--a){
        for(ll b = m-1;b>=0;--b) {
            ll a1 = trans(b);
            ll b1 = trans(a);
            if (a1<h && b1<m)
                last = {a,b};
            ans[a][b] = last;
        }
    }
    while(t--){
        ll a,b;
        char ch;
        cin>>a>>ch>>b;
        if (ans[a][b].first<10)cout<<0;
        cout<<ans[a][b].first<<":";
        if (ans[a][b].second<10)cout<<0;
        cout<<ans[a][b].second<<endl;
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;

    cin>>t;
    while(t--)
        solve();

    return 0;
}