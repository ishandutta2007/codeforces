//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 307;
const ll MAXN = 300;
const ll INF = 1E18;
void solve(){
    ll a,b;
    cin>>a>>b;
    ll res = INF,base = 0;
    for(ll i = 0;i<=1000;++i){
        ll x = a,cnt = 0;
        if (b>1) {
            while (x != 0) {
                x /= b;
                ++cnt;
            }
            res = min(res, cnt + base);
        }
        ++base;
        ++b;
    }
    cout<<res<<endl;
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