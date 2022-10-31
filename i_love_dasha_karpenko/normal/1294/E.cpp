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
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 4*10E4+7;
const ll INF = 10E17;
const ll MAXN = 10E8+7;
vector<vector<ll> > A;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    A.resize(n+1);
    forn(i,n){
        A[i].resize(m+1);
        forn(j,m)cin>>A[i][j];
    }
    ll ans = 0;
    forn(j,m){
        map<ll,ll> M;
        forn(i,n){
            ll r = A[i][j]-j;
            if (r%m==0 && r/m<n){
                ll dpos = i-r/m-1;
                if (dpos<0)dpos+=n;
                if (dpos>=n)dpos-=n;
                M[dpos]++;
            }
        }
        ll res = n;
        for(pp to:M){
            res = min(res,to.fi+n-to.sc);
        }
        ans+=res;
        //cout<<res<<endl;
    }
    cout<<ans<<endl;

    return 0;
}