#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll DIM = 100007;
const ll INF = 10e16;
const ll MOD1 = (10e9)+7;
const ll MOD2 = 2147483647;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)

int main()
{
    //cout<<'A'-33<<endl;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll a,b; cin>>a>>b;
        ll delta = b-a;
        ll r1 = delta/5;
        ll r2 = delta%5/2;
        ll r3 = delta%5%2;
        cout<<abs(r1+r2+r3)<<endl;
    }
    return 0;
}

// 5
// 0 1 0 1 0 1010
// 1 3 9  27
// 1 7 16 70
// 1 2 1 0