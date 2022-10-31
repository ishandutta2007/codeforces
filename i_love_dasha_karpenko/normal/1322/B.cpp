#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
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
const ll DIM = 4*10E4+7;
const ll INF = 10E16;
const ll MAXN = 2*10E6+7;
ll A[DIM],mod[2][MAXN],suf[2][MAXN];
pp val[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    ll n;
    cin>>n;
    pp mx = {0,0};
    forn(i,n){
        cin>>A[i];
        if (A[i]>mx.sc)mx.sc =A[i];
        if (mx.sc>mx.fi)swap(mx.fi,mx.sc);
    }
    ll res = 0;
    for(ll bit = 0;po(bit)<=mx.fi+mx.sc;bit++){
        ll vv = po(bit);
        for(ll i = 0;i<=vv;i++)mod[0][i] = mod[1][i] = 0;
        forn(i,n){
            val[i].fi = A[i]%vv;
            if (A[i]&vv)val[i].sc = 1;
            else val[i].sc = 0;
            mod[val[i].sc][val[i].fi]++;
        }
        ll cnt = 0;
        suf[0][vv+1]=suf[1][vv+1] = 0;
        for(ll i = vv;i>=0;i--){
            suf[1][i] = suf[1][i+1]+mod[1][i];
            suf[0][i] = suf[0][i+1]+mod[0][i];
        }
        for(ll i = 0;i<=vv;i++){


            //sum-=mod[0][i];
            cnt+=(mod[1][i]*(suf[0][0]-suf[0][vv-i]))%2;

            if (vv-i!=i){
                if (i<vv-i){
                    cnt+=(mod[1][i]*suf[1][vv-i])%2;
                    cnt+=(mod[0][i]*suf[0][vv-i])%2;
                }
                else{
                    cnt+=mod[1][i]*suf[1][i+1];
                    cnt+=((mod[1][i]-1)*mod[1][i])/2;
                    cnt+=mod[0][i]*suf[0][i+1];
                    cnt+=((mod[0][i]-1)*mod[0][i])/2;
                }
                //cnt+=mod[1][i]*mod[1][vv-i];
            }
            else{
                cnt+=(mod[1][i]*suf[1][vv-i+1])%2;
                cnt+=(mod[0][i]*suf[0][vv-i+1])%2;
                cnt+=(mod[1][i]*(mod[1][i]-1)/2)%2;
                cnt+=(mod[0][i]*(mod[0][i]-1)/2)%2;
                //cnt+=mod[1][i]*(mod[1][vv-i]-1)/2;
            }

        }
        if (cnt%2!=0)res^=vv;
    }
    cout<<res<<endl;
    return 0;
}