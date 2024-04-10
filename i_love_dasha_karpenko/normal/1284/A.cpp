#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 20+7;
const ll INF = 10E10;
string A[DIM],B[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m; cin>>n>>m;
    forn(i,n)cin>>A[i];
    forn(i,m)cin>>B[i];
    ll q; cin>>q;
    forn(query,q){
        ll y; cin>>y;
        ll r1 = y%n;
        if (r1==0)r1 = n;
        ll r2 = y%m;
        if (r2==0)r2 = m;
        cout<<A[r1]<<B[r2]<<endl;
    }
    return 0;
}