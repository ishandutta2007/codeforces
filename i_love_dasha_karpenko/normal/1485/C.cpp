//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
const ll INF = 1E18;
ll x,y;

void solve(){
    ll res = 0;
    cin>>x>>y;
    for(ll c = 1;c*(c+2)<=x;++c){
        ll l = (c+2);
        ll r = x/c;
        r = min(r,y+1);
        res+=max(0ll,r-l+1);
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