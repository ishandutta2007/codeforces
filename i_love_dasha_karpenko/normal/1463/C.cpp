#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E5+7;
const ll INF = 1E18;
ll x[DIM],t[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        ll cur = 0,to = 0;
        for(ll i = 1;i<=n;++i){
            cin>>t[i]>>x[i];
        }
        ll res = 0;
        t[n+1] = INF;
        for(ll i = 1;i<=n;++i){
            if (cur==to){
                to = x[i];
            }
            if (cur<to){
                ll l = cur,r = min(to,cur+(t[i+1]-t[i]));
                if (l<=x[i] && x[i]<=r)++res;
                cur = r;
            }
            else{
                ll l = max(to,cur-(t[i+1]-t[i])),r = cur;
                if (l<=x[i] && x[i]<=r)++res;
                cur = l;
            }

        }
        cout<<res<<endl;
    }
    return 0;
}