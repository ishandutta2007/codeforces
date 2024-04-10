#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 1E5+7;
const ll INF = 1E18;
ll A[DIM],B[DIM];
ll n;
ll F(ll x){
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        res+=abs(A[i]-x);
    }
    return res;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n;
        ll sum1 = 0,sum2 = 0;
        for(ll i = 1;i<=n;++i){
            cin>>A[i]>>B[i];
            sum1+=A[i];
            sum2+=B[i];
        }
        ll res = 1;
        {
            ll l = 0,r = 1E9;
            while(r-l>3){
                ll tl = (l*2+r)/3;
                ll tr = (l+r*2)/3;
                if (F(tl)<F(tr))r = tr;
                else l = tl;
            }
            for(ll i = l;i<=r;++i){
                if (F(i)<F(l))l = i;
            }
            r = l;

            for(ll mult = (1ll<<32);mult>=1;mult/=2){
                if (F(l-mult)==F(l))l = l-mult;
            }
            for(ll mult = (1ll<<32);mult>=1;mult/=2){
                if (F(r+mult)==F(r))r = r+mult;
            }
            res *= r-l+1;
        }
        for(ll i = 1;i<=n;++i){
            swap(A[i],B[i]);
        }
        {
            ll l = 0,r = 1E9;
            while(r-l>3){
                ll tl = (l*2+r)/3;
                ll tr = (l+r*2)/3;
                if (F(tl)<F(tr))r = tr;
                else l = tl;
            }
            for(ll i = l;i<=r;++i){
                if (F(i)<F(l))l = i;
            }
            r = l;

            for(ll mult = (1ll<<32);mult>=1;mult/=2){
                if (F(l-mult)==F(l))l = l-mult;
            }
            for(ll mult = (1ll<<32);mult>=1;mult/=2){
                if (F(r+mult)==F(r))r = r+mult;
            }
            res *= r-l+1;
        }
        cout<<res<<endl;
    }
    return 0;
}