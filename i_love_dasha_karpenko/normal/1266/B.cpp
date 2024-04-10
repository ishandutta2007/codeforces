#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 200007+7;
const ll INF = 10E10;

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    ll sum = 14;
    forn(q,n){
        ll x; cin>>x;
        ll r = x%sum;
        if (x>sum && r>0 && r<=6)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}