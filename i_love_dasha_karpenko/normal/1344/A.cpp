#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
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
const ll DIM = 2E5+7;
const ll INF = 1E18;

ll n,A[2*DIM];
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cin>>A[n];
        A[n*2] = A[n];
        forn(i,n-1){
            cin>>A[i];
            A[i+n] = A[i];
        }
        set<ll> S;
        forn(i,n){
            ll pos = (A[i]+i)%n;
            if (pos<0){
                pos+=n;
            }
            S.insert(pos);
        }
        if (S.size()!=n)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}