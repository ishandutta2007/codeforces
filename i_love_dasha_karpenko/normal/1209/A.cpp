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

ll A[DIM],vis[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n)cin>>A[i];
    sort(A+1,A+1+n);
    ll res=  0;
    forn(i,n){
        if (vis[i]==1)continue;
        for(ll j = i;j<=n;j++){
            if (A[j]%A[i]==0)vis[j] = 1;
        }
        res++;
    }
    cout<<res<<endl;
    return 0;
}