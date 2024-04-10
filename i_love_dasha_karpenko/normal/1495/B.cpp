//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
const ll INF = 1E9;
ll A[DIM],grow[2][DIM],grow1[2][DIM],MX[2][DIM],S[2][DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)
        cin>>A[i];
    for(ll i = 1;i<=n;++i){
        if (A[i]<A[i-1]){
            grow[0][i] = 0;
        }
        else if (i!=1){
            grow[0][i] = grow[0][i-1]+1;
        }
    }
    for(ll i = n;i>=1;--i){
        if (A[i]<A[i+1]){
            grow[1][i] = 0;
        }
        else if (i!=n){
            grow[1][i] = grow[1][i+1]+1;
        }
    }
    ///////////////
    for(ll i = 1;i<=n;++i){
        if (A[i]>A[i-1]){
            grow1[0][i] = 0;
        }
        else if (i!=1){
            grow1[0][i] = grow1[0][i-1]+1;
        }
    }
    for(ll i = n;i>=1;--i){
        if (A[i]>A[i+1]){
            grow1[1][i] = 0;
        }
        else if (i!=n){
            grow1[1][i] = grow1[1][i+1]+1;
        }
    }
    ///////////////////
    for(ll i = 1;i<=n;++i){
        MX[0][i] = max({MX[0][i-1],grow1[0][i],grow1[1][i]});
        S[0][i] = max(S[0][i-1],grow1[0][i]);
    }
    for(ll i = n;i>=1;--i){
        MX[1][i] = max({MX[1][i+1],grow1[0][i],grow1[1][i]});
        S[1][i] = max(S[1][i+1],grow1[1][i]);
    }
    ///////////////////
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        ll flag = 0;
        ll mx = 0;
        for(ll j = 0;j<2;++j){
            ll pos = i + (-1+j*2)*(grow[j][i]-(1-grow[j][i]%2));
            ll p = i+(-1+j*2)*grow[j][i];
            if (!j)
            mx = max(mx,MX[0][p-1]);
            else mx = max(mx,MX[1][p+1]);
            ll step = max(grow1[0][pos],grow1[1][pos]);
            if (grow[j^1][i]<=step)flag = 1;
        }
        if (mx>=max(grow[0][i],grow[1][i]) || S[0][i-1]>=max(grow[0][i],grow[1][i]) || S[1][i+1]>=max(grow[0][i],grow[1][i]))
            flag = 1;
        if (!flag)
            ++res;
    }
    cout<<res<<endl;
    return 0;
}