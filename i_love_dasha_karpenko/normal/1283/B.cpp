#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree <ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define fi first
#define sc second
#define x1 Tanya
#define y1 Romanova
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define endl '\n'
const ll DIM = 2*10E4+7;
const ll INF = 10E17;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qe,t){
        ll n,k; cin>>k>>n;
        ll q = k/n;
        k-=q*n;
        ll res=q*n;
        res+=min(k,n/2);
        cout<<res<<endl;
    }
    return 0;
}