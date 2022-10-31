//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;

void solve(){
    ll n,k;
    cin>>n>>k;
    for(ll i = 1;i<=k-3;++i)cout<<1<<' ',n--;
    if (n%4==0){
        cout<<n/2<<' '<<n/4<<' '<<n/4<<endl;
    }
    else{
        ll mult = 1;
        while(n%2==0){
            n/=2;
            mult*=2;
        }
        ll a = n / 2, b = n / 2, c = 1;
        cout << a * mult << ' ' << b * mult << ' ' << c * mult << endl;
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