#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll MOD = 10E8+7;
const ll INF = 10E15;
const ll base = 31;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll r,b,k;
        cin>>r>>b>>k;
        ll g = __gcd(r,b);
        r/=g;
        b/=g;
        if (r>b)swap(r,b);
        if (1+(b-1)/r-((b-1)%r==0)<k)cout<<"OBEY\n";
        else cout<<"REBEL\n";
    }
    return 0;
}