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
const ll DIM = 10E5+7;
const ll INF = 10E17;

ll A[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tc;
    cin>>tc;
    forn(qe,tc){
        ll n; cin>>n;
        forn(i,n){
            cin>>A[i];
        }
        vector<ll> V;
        ll res = 0;
        forn(i,n){
            if (A[i]!=-1 && A[i-1]!=-1 && i>1)res = max(res,abs(A[i]-A[i-1]));
        }
        forn(i,n){
            if (A[i]!=-1)continue;
            if (i>1 && A[i-1]!=-1)V.pb(A[i-1]);
            if (i<n && A[i+1]!=-1)V.pb(A[i+1]);
        }
        if (V.empty()){
            cout<<"0 1\n";
            continue;
        }
        sort(V.begin(),V.end());
        ll k = (V[0]+V.back())/2;
        cout<<max(res,V.back()-k)<<' '<<k<<endl;
    }
    return 0;
}