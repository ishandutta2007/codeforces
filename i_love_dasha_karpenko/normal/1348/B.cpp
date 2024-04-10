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
#define po(x) ((unsigned long long)(1)<<x)
const ll DIM = 500+7;
const ll INF = 10E17;
ll n,k,A[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        set<ll> S;
        forn(i,n){
            cin>>A[i];
            S.insert(A[i]);
        }
        if (S.size()>k){
            cout<<"-1\n";
            continue;
        }
        ll ptr = 1;
        while(S.size()<k){
            if (S.count(ptr)==1)++ptr;
            S.insert(ptr);
        }
        cout<<S.size()*n<<endl;
        forn(i,n){
            for(ll to:S)cout<<to<<' ';
        }
        cout<<endl;
    }
    return 0;
}