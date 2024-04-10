#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
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
const ll DIM = 10E4+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll MAXN = 70;
ll cnt[MAXN+1],need[MAXN+1];
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll u,v;
    cin>>u>>v;
    ll bit = 0;
    while(v>0){
        if (v&1)cnt[bit] = 1;
        bit++;
        v/=2;
    }
    bit = 0;
    while(u>0){
        if (u&1)need[bit] = 1;
        bit++;
        u/=2;
    }
    for(ll i = MAXN;i>=0;--i){
        if (cnt[i]%2!=need[i]){
            if (cnt[i]>0){
                if (i==0){
                    cout<<"-1\n";
                    return 0;
                }
                cnt[i-1]+=2;
                cnt[i]--;
            }
            else{
                cout<<"-1\n";
                return 0;
            }
        }
        if (i>0){
            cnt[i-1]+=(cnt[i]-cnt[i]%2)*2;
            cnt[i]%=2;
        }
    }
    ll res = 0;
    for(ll i = 0;i<=MAXN;i++){
        ll hh = 4;
        cnt[i+1]+=(cnt[i]/hh)*2;
        //hh/=2;
        cnt[i]%=hh;
        res=max(res,cnt[i]);
    }
    cout<<res<<endl;
    ll po = 1;
    for(ll i = 0;i<=MAXN;i++){
        while(cnt[i]>0){
            ll pn = po;
            ll num = 0;
            for(ll j = i;j<=MAXN;j++){
                if (cnt[j]>0){
                    cnt[j]--;
                    num+=pn;
                }
                pn*=2;
            }
            cout<<num<<' ';
        }
        po*=2;
    }
    cout<<endl;
    return 0;
}
// a[i]-b[i]>b[j]-a[j]