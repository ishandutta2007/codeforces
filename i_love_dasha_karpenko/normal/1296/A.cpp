#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
//template<typename TN>
//typedef tree<TN,null_type,less<TN>,rb_tree_tag,tree_order_statistics_node_update> super_set<TN>;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 2*10E4 +7;
const ll INF = 10E17;
const ll MAXN = 10E5;

//super_set<pp> S;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qe,t){
        ll n;
        cin>>n;
        ll cnt1 = 0,cnt2 = 0;
        forn(i,n){
            ll x;
            cin>>x;
            if (x%2==0)cnt1++;
            else cnt2++;
        }
        if (cnt1>0 && cnt2>0)cout<<"YES\n";
        else if (cnt1==0 && n%2!=0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}