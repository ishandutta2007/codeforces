#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update> ms;
const ll DIM = 200000+7;
const ll INF = 10e16;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)
struct node{
    pp a;
    ll pos;
};
const bool operator>(const node &a,const node &b){
    return a.a>b.a;
}
ll n,m,A[DIM],ans[DIM];
node Q[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n)cin>>A[i];
    cin>>m;
    forn(query,m){
        cin>>Q[query].a.fi>>Q[query].a.sc;
        Q[query].pos = query;
    }
    sort(Q+1,Q+1+m,greater<node>());
    set<pp> S;
    ms S1;
    forn(i,n){
        S.insert({A[i],i});
        S1.insert({i,A[i]});
    }
    forn(query,m){
        ll k = Q[query].a.fi,pos = Q[query].a.sc;
        while(S.size()>k){
            ll t = (*S.begin()).fi;
            auto it = S.upper_bound({t,INF});
            --it;
            S1.erase({(*it).sc,(*it).fi});
            S.erase(it);

        }
        ans[Q[query].pos] = (*S1.find_by_order(pos-1)).sc;
    }
    forn(i,m)cout<<ans[i]<<endl;
    return 0;
}