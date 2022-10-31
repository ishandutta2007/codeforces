#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 1e18;
ll A[DIM],last[DIM];
map<ll,vector<ll> > M;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n)cin>>A[i];
    ll r = 0;

    forn(i,n){
        r+=A[i];
        M[r].pb(i);
    }
    for(auto it = M.begin();it!=M.end();it++){
        reverse((*it).sc.begin(),(*it).sc.end());
    }
    ll pref = 0;

    if (!M[0].empty()){
        last[M[0].back()] = 1;
    }
    forn(i,n){

        if (!M[pref].empty() && M[pref].back()<i)
        M[pref].pop_back();
        if (!M[pref].empty()){
            last[M[pref].back()] = i;
        }
        pref+=A[i];
    }
    ll res = 0;
    forn(i,n){
        last[i] = max(last[i],last[i-1]);
        res+=i-last[i];
    }
    cout<<res<<endl;
    return 0;
}