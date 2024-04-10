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
const ll DIM = 60+7;
const ll INF = 1e8;

ll po[DIM],cnt[DIM],oldcnt[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    forn(i,60)po[i] = po[i-1]*2;
    ll t;
    cin>>t;
    while(t--){
        ll d,m;
        cin>>d>>m;
        ll res = 1;
        oldcnt[0] =1;
        for(ll i = 1;po[i]<=d;++i){
            oldcnt[i] = min(d-po[i]+1,po[i]);
            res = (res+oldcnt[i])%m;
        }
        ll flag = 1;
        while(flag){
            flag = 0;
            ll sum = oldcnt[0]%m;
            for(ll i = 1;po[i]<=d;++i){
                ll g = min(d-po[i]+1,po[i])%m;
                cnt[i] = (sum*g)%m;
                sum = (sum+oldcnt[i])%m;
                res = (res+cnt[i])%m;
                if (cnt[i]!=0)flag = 1;
            }

            for(ll i = 0;po[i]<=d;++i){
                oldcnt[i] = cnt[i];
            }
        }
        cout<<res%m<<endl;
    }
    return 0;
}