#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 5E5+7;
const ll MOD = 1E9+7;
ll A[DIM],flag[DIM],nxt[DIM],P[DIM];
ll F(ll x){
    if (x==P[x])return x;
    return P[x] = F(P[x]);
}
void unite(ll x,ll y){
    x = F(x);
    y = F(y);
    if (x>y)swap(x,y);
    P[x] = y;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=m;++i){
        P[i] = i;
        nxt[i] = i;
    }
    ll res = 0;
    vector<ll> V;
    for(ll i = 1;i<=n;++i){
        ll k;
        cin>>k;
        if (k==1){
            ll a;
            cin>>a;
            a = F(a);
            if (flag[a]==0){
                flag[a] = 1;
                ++res;
                V.push_back(i);
            }

        }
        else{
            ll a,b;
            cin>>a>>b;
            a = F(a);
            b = F(b);
            if (a>b)swap(a,b);
            if (a==b)continue;
            if (flag[a]==0){
                flag[a] = 1;
                ++res;
                V.push_back(i);
                unite(a,b);
            }
            else if (flag[b]==0){
                flag[b] = 1;
                ++res;
                V.push_back(i);
            }

        }
    }
    ll ans = 1;
    for(ll i = 1;i<=res;++i)
        ans = (ans*2)%MOD;
    cout<<ans<<' '<<V.size()<<endl;
    for(ll to:V)cout<<to<<' ';
    cout<<endl;
    return 0;
}