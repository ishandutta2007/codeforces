#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll INF = 1E18;
const ll DIM = 3E5+7;
ll A[3][DIM],mi[3],sum[3];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    t = 1;
    while(t--){
        ll n[3];
        cin>>n[0]>>n[1]>>n[2];
        for(ll mas = 0;mas<3;++mas){
            mi[mas] = INF;
            sum[mas] = 0;
            for(ll i = 1;i<=n[mas];++i)
            {
                ll x;
                cin>>x;
                mi[mas] = min(mi[mas],x);
                sum[mas]+=x;
            }
        }
        vector<ll> V = {0,1,2};
        ll res = 0;
        do{
            ll a = V[0],b = V[1],c = V[2];
            ll r = sum[a]+sum[b]+sum[c]-(mi[b]+mi[c])*2;
            res = max(res,r);
            r = sum[a]+sum[b]-sum[c];
            res = max(res,r);
        }while(next_permutation(V.begin(),V.end()));
        cout<<res<<endl;
    }
    return 0;
}