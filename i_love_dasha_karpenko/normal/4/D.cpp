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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 5000+7;
const ll INF = 10E17;
struct node{
    ll fi,sc,pos;
};
const bool operator>(const node &a,const node &b){
    if (a.fi==b.fi)return a.sc>b.sc;
    return a.fi>b.fi;
}
ll dp[DIM],P[DIM];
node A[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,w,h; cin>>n>>w>>h;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
        A[i].pos = i;
    }
    sort(A+1,A+1+n,greater<node>());
    ll res = 0,st = -1;
    forn(i,n){
        dp[i] = 1;
        P[i] = -1;
        forn(j,n){
            if (A[j].fi>A[i].fi && A[j].sc>A[i].sc && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
                P[i] = j;
            }
        }
        if (res<dp[i] && A[i].fi>w && A[i].sc>h){
            res = dp[i];
            st = i;
        }
    }
    cout<<res<<endl;
    vector<ll> ans;
    for(;st!=-1;){
        ans.pb(A[st].pos);
        st = P[st];
    }
    //reverse(ans.begin(),ans.end());
    for(ll to:ans)cout<<to<<' ';
    cout<<endl;
    return 0;
}