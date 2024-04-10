#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 100+7;
const ll INF = 1E18;
ll A[DIM][DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=m;++j){
                cin>>A[i][j];
            }
        }
        ll ans = 0;
        for(ll i = 1;i<=n/2;++i){
            for(ll j = 1;j<=m/2;++j){
                ll a = A[i][j],b = A[i][m-j+1],c = A[n-i+1][j],d = A[n-i+1][m-j+1];
                vector<ll> V = {a,b,c,d};
                sort(V.begin(),V.end());
                ll cnt = 4,sum = a+b+c+d;
                ll res = INF,mi = 0,mx = a;
                for(ll to:V){
                    mx = to;
                    if (sum>cnt*mx){
                        res = min(res,sum-cnt*mx);
                    }
                    else if (sum<cnt*mi){
                        res = min(res,cnt*mi-sum);
                    }
                    else if (cnt!=0){
                        res = min(res,min(sum%cnt,(cnt-sum%cnt)%cnt));
                    }
                    else{
                        res = min(res,sum);
                    }
                    cnt-=2;
                    sum-=to*2;
                    mi = to;
                }
                ans+=res;

            }
        }
        if (n%2!=0){
            ll i = n/2+1;
            for(ll j = 1;j<=m/2;++j){
                ll a = A[i][j],b = A[i][m-j+1];
                ans+=abs(a-b);
            }
        }
        if (m%2!=0){
            ll j = m/2+1;
            for(ll i = 1;i<=n/2;++i){
                ll a = A[i][j],b = A[n-i+1][j];
                ans+=abs(a-b);
            }
        }
        cout<<ans<<endl;
    }
    return 0;

}