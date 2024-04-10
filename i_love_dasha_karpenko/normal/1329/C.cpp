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
//#define po(x) (1ll<<x)
const ll DIM = 2*1048576+7;
const ll INF = 1e8;

ll po[64],A[DIM];
ll F(ll v,ll depth){
    ll l = v*2,r = v*2+1;
    if (A[l]==A[r] && A[l]==0)return depth;
    if (A[l]>A[r])return F(l,depth+1);
    else return F(r,depth+1);
}
void del(ll v,ll depth){
    ll l = v*2,r = v*2+1;
    if (A[l]==A[r] && A[l]==0){
        A[v] = 0;
        return;
    }
    if (A[l]>A[r]){
        A[v] = A[l];
        del(l,depth+1);
    }
    else{
        A[v] = A[r];
        del(r,depth+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    po[0] = 1;
    forn(i,60)po[i] = po[i-1]*2;
    ll t;
    cin>>t;
    vector<ll> ans;
    while(t--){
        ll h,g;
        cin>>h>>g;
        ll n = po[h]-1;
        forn(i,n)cin>>A[i];
        queue<pp> Q;
        Q.push({1,1});
        ll sz = n;
        ll need = po[g]-1;
        ans.clear();
        while(!Q.empty() && sz>need){
            pp k = Q.front();
            if (F(Q.front().fi,Q.front().sc)==g){
                ll v = Q.front().fi;
                ll l = v*2,r = v*2+1;
                if (A[l]!=0)Q.push({l,Q.front().sc+1});
                if (A[r]!=0)Q.push({r,Q.front().sc+1});
                Q.pop();
            }
            else {
                sz--;
                del(Q.front().fi,Q.front().sc);
                ans.pb(Q.front().fi);
            }
        }
        ll res = 0;
        forn(i,need)res+=A[i];
        cout<<res<<endl;
        for(ll to:ans)cout<<to<<' ';
        forn(i,n)A[i] = 0;
        cout<<endl;

    }
    return 0;
}