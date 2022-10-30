#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg

#define po(x) (1ll<<x)
const ll DIM = 2*10E4+7;
const ll INF = 10e16;
const ll MOD = 998244353 ;
const ll MAXN = 1000000000;
ll vis[DIM],A[DIM];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k; cin>>n>>k;
    if (k==1){
        cout<<"! 1"<<endl;
        return 0;
    }
    vector<pp> nums;
    forn(t,2){
        ll c = 0;
        cout<<"? ";
        forn(i,n){
            if (c==k)break;
            if (vis[i]==0){cout<<i<<' '; c++;}
        }
        cout<<endl;
        ll pos,num; cin>>pos>>num;
        vis[pos] = 1;
        A[pos] = num;
        nums.pb({num,pos});
    }
    //sort(nums.begin(),nums.end());
    ll e = nums[1].sc,r = nums[0].sc,rr = nums[0].fi,ee = nums[1].fi;
    vector<ll> V;
    forn(i,n){
        if (V.size()==k-1)break;
        if (vis[i]==0)V.pb(i);
    }

    ll cnt = 1;
    for(ll t:V){
        cout<<"? "<<e<<' ';
        for(ll to:V)if (to!=t)cout<<to<<' ';
        cout<<r<<' ';
        cout<<endl;
        ll pos,num; cin>>pos>>num;
        if (pos==e){
            if (ee>rr)cnt++;
        }
        if (pos!=e){
            if (ee<rr)cnt++;
        }
    }
    cout<<"! "<<cnt<<endl;
    return 0;

}