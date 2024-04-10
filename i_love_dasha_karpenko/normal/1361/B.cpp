#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E6+140;
const ll INF = 1E16;
const ll MOD = 1E9+7;
ll A[DIM];
ll binpow(ll x,ll power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
pp S[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,p;
        cin>>n>>p;
        forn(i,n){
            cin>>A[i];
        }
        sort(A+1,A+1+n,greater<ll>());
        ll sum[2];
        sum[0] = sum[1] = 0;
        ll mi = 0,flag = 0;
        if (p==1){
            cout<<n%2<<endl;
            continue;
        }
        forn(i,n){
            sum[0] = (sum[mi]+binpow(p,A[i]))%MOD;
            ll st = A[i];
            ++i;

            ll pos = 0;
            S[pos] = {0,0};
            while(i<=n){
                ll cur = A[i];
                while(pos>0 && S[pos].fi==cur){
                    if (S[pos].sc==p-1){
                        pos--;
                        ++cur;
                    }
                    else break;
                }
                if (pos>0 && S[pos].fi==cur){
                    S[pos].sc++;
                }
                else S[++pos] = {cur,1};
                if (pos>0 && S[pos].fi==st)break;
                ++i;
            }
            ll sz = pos;
            ll last = S[1].fi;
            if (sz!=1)last = INF;
            while(pos>0){
                sum[1]=(((binpow(p,S[pos].fi))*S[pos].sc)%MOD+sum[1])%MOD;
                --pos;
            }
            if ( sz!=1 || last!=st){

                if (i+1<=n)n/=0;
                break;
            }

        }


        ll dif = sum[0]-sum[1];
        while (dif<0)dif+=MOD;
        cout<<dif<<endl;

    }
    return 0;
}