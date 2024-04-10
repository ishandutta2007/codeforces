#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
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
const ll DIM = 500+7;
const ll INF = 1E16;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],B[DIM];
ll ca[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n){
            cin>>A[i];
        }
        forn(i,n){
            cin>>B[i];
        }
        vector<pp> V1,V2;
        forn(i,n/2){
            pp a = {A[i],A[n-i+1]};
            if (a.fi>a.sc)swap(a.fi,a.sc);
            V1.pb(a);
        }
        forn(i,n/2){
            pp a = {B[i],B[n-i+1]};
            if (a.fi>a.sc)swap(a.fi,a.sc);
            V2.pb(a);
        }
        sort(V1.begin(),V1.end());
        sort(V2.begin(),V2.end());
        ll ff  =0;
        for(ll i = 0;i<n/2;++i){
            if (V1[i]!=V2[i]){
                ff = 1;
                break;
            }
        }
        if (n%2!=0 && A[n/2+1]!=B[n/2+1])ff = 1;
        if (ff==0)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}