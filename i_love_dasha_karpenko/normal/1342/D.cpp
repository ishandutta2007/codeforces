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
const ll INF = 1e19;

ll suf[DIM];
pp A[DIM];
ll sz[DIM];
vector<ll> ans[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    forn(i,n){
        cin>>A[i].fi;
        A[i].sc = i;
    }
    forn(i,k)cin>>sz[i];
    sort(A+1,A+1+n);
    ll ptr = n;
    ll cnt = 0;
    for(ll i = k;i>=1;--i){
        while(ptr>=1 && A[ptr].fi>=i){
            cnt++;
            --ptr;
        }
        suf[i] = cnt;
    }
    ll l = 0,r = n;
    while(l!=r){
        ll tm = (l+r)/2;
        ll cnt = 0;
        ll flag = 0;
        for(ll i = k;i>=1;--i){
            ll cap = sz[i]*tm;
            if (cap<suf[i]){
                flag = 1;
                break;
            }
        }
        if (flag==1)l = tm+1;
        else r = tm;
    }
    cout<<l<<endl;
    ptr = 0;
    for(ll i = n;i>=1;--i){
        ans[ptr+1].pb(A[i].fi);
        ++ptr;
        ptr%=l;
    }
    forn(i,l){
        cout<<ans[i].size()<<' ';
        for(ll to:ans[i])cout<<to<<' ';
        cout<<endl;
    }
    return 0;
}