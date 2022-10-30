#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long ll;

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
#define log sdfdsfdsf

const ll DIM = 1E6+7;
const ll MOD = 1e9+7;

const ll INF = 1E8;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
const ll masksz = 8;
ll dp[DIM][masksz];
ll A[DIM][4],cur[4],old[4];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    if (n>3 && m>3){
        cout<<-1<<endl;
        return 0;
    }


    ll flag=  0;
    if (n<m){
        swap(n,m);
        flag = 1;
    }
    if (flag){


        forn(j,m){
            forn(i,n){
                char ch;
                cin>>ch;
                A[i][j] = ch-'0';
            }
        }
    }
    else{
        forn(i,n){
            forn(j,m){
                char ch;
                cin>>ch;
                A[i][j] = ch-'0';
            }
        }
    }
    ll sz = po(m);
    for(ll mask = 0;mask<sz;++mask){
        forn(j,m){
            if (A[1][j]!=((mask&po(j-1))>0)){
                dp[1][mask]++;
            }
        }
    }
    for(ll i = 2;i<=n;++i){
        for(ll mask = 0;mask<sz;++mask){
            dp[i][mask] = INF;
            ll cnt = 0;
            forn(j,m){
                if (A[i][j]!=((mask&po(j-1))!=0)){
                    ++cnt;
                }
                cur[j] = ((mask&po(j-1))!=0);
            }
            for(ll prev = 0;prev<sz;++prev){
                forn(j,m){
                    old[j] = ((prev&po(j-1))!=0);
                }
                ll fl = 0;
                for(ll j = 2;j<=m;++j){
                    ll sum = old[j]+cur[j]+old[j-1]+cur[j-1];
                    if (sum%2==0)fl = 1;
                }
                if (fl)continue;
                dp[i][mask] = min(dp[i][mask],dp[i-1][prev]+cnt);
            }
        }
    }
    ll res = INF;
    for(ll mask = 0;mask<sz;++mask)res = min(res,dp[n][mask]);
    cout<<res<<endl;



    return 0;
}