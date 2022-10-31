#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E4+7;
const ll INF = 1E16;

ll pref[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n = s.length();
        ll res = n;
        ll sum = 0;
        for(ll i = 0;i<n;++i){
            if (s[i]=='1')++sum;
            pref[i] = sum;
        }
        //res = min(res,n-pref[n-1]);
        for(ll i = 0;i<n;++i){
            res = min(res,pref[i]+(n-i-1)-pref[n-1]+pref[i]);
            res = min(res,i+1-pref[i]+pref[n-1]-pref[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}