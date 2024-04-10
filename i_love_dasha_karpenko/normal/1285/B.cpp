#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 10E4 +7;
const ll INF = 10E17+7;
ll A[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n; cin>>n;
        ll mxsum = 0,sum = 0,allsum = 0;
        forn(i,n){
            ll x; cin>>x;
            allsum+=x;
            A[i] = x;
        }
        forn(i,n-1){
            ll x = A[i];
            sum+=x;
            if (sum<0)sum = 0;
            mxsum = max(mxsum,sum);
        }
        sum = 0;
        for(ll i = 2;i<=n;i++){
            ll x= A[i];
            sum+=x;
            if (sum<0)sum = 0;
            mxsum = max(mxsum,sum);
        }
        if (allsum>mxsum)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}