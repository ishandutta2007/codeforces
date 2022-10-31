#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E5+14;
const ll INF = 1E17;
const ll MAXN = 2E5+7;
ll A[DIM],ct[DIM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll fl = 0;
        ll flag = 0;
        forn(i,n){
            cin>>A[i];
            if (i>1 && A[i]>=k && A[i-1]>=k)flag = 1;
            if (i>2 && A[i]>=k && A[i-2]>=k) flag = 1;
            if (A[i]==k)fl = 1;
        }
        if (n==1)flag = 1;
        if (flag+fl==2)cout<<"yes\n";
        else cout<<"no\n";

    }
    return 0;
}