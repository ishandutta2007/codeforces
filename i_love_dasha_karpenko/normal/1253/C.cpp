#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 2*10E4 +7;
const ll INF = 10E17+7;
ll A[DIM],rot[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m; cin>>n>>m;
    forn(i,n)cin>>A[i];
    sort(A+1,A+1+n);
    ll res = 0;
    forn(i,n){
        rot[i%m]+=A[i];
        res+=rot[i%m];
        cout<<res<<' ';
    }

    return 0;
}

// 1 2 3
//