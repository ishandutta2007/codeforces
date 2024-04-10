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
const ll DIM = 2*10E2+7;
const ll INF = 10E16;

ll A[DIM],B[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    ll t;
    cin>>t;

    while(t--){
    ll n;
    cin>>n;
    forn(i,n)cin>>A[i];
    forn(i,n)cin>>B[i];
    sort(A+1,A+1+n);
    sort(B+1,B+1+n);
    forn(i,n)cout<<A[i]<<' ';
    cout<<endl;
    forn(i,n)cout<<B[i]<<' ';
    cout<<endl;
    }
    return 0;
}