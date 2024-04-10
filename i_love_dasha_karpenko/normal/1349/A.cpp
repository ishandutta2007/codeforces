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
const ll DIM = 2E5+14;
const ll INF = 1E10;
const ll MAXN = 2E5+7;
ll A[DIM];
vector<ll> M[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    forn(pos,n){
        ll x;
        cin>>x;
        for(ll i = 2;i<=sqrt(x);++i){
            if (x%i)continue;
            ll cnt = 1;
            while(x%i==0){
                x/=i;
                cnt*=i;
            }

            M[i].pb(cnt);
        }
        if (x!=1)M[x].pb(x);
    }
    ll res = 1;
    forn(i,MAXN){
        if (M[i].size()<n-1)continue;
        sort(M[i].begin(),M[i].end());
        if (M[i].size()==n-1)res*=M[i][0];
        else res*=M[i][1];
    }
    cout<<res<<endl;
    return 0;
}