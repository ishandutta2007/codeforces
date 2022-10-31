//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
ll A[DIM];
ll V[DIM];
void solve(){
    ll n,m;
    cin>>n>>m;

    for(ll i = 1;i<=n;++i) {
        ll x;
        cin>>x;
        V[x%m]++;
    }
    ll res = 0;
    for(ll i = 1;i<m;++i){
        if ((i+i)%m==0) {
            if (V[i]!=0)++res;
            V[i] = 0;
            continue;
        }
        ll rev = (m-i)%m;
        if (V[i]>V[rev]){
            ll delta = V[rev];
            V[rev] = 0;
            V[i]-=delta+1;
            ++res;
        }
        else if (V[i]==V[rev]){
            if (V[i]==0)continue;
            ++res;
            V[i] = V[rev] = 0;
        }
    }
    if (V[0]!=0)++res;
    for(ll i = 1;i<m;++i){
        res+=V[i];
        V[i] = 0;
    }
    V[0] = 0;
    cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}