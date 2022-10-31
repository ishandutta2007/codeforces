//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
const ll INF = 1E15;
const ll MAXN = 2E7;
char vis[MAXN+7];
int ans[MAXN+7];
ll solve(ll c,ll d,ll x){

    if ((x+d)%c){
        return 0;
    }
    ll n = (x+d)/c;
    return ans[n];
}
void comp(){
    ll c,d,x;
    cin>>c>>d>>x;
    ll res = 0;
    for(ll div = 1;div*div<=x;++div){
        if (x%div)continue;
        res+=solve(c,d,x/div);
        if (div!=x/div)res+=solve(c,d,div);
    }
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ans[1] = 1;
    for(ll i = 2;i<=MAXN;++i){
        ans[i] = (1ll<<ans[i]);
        if (vis[i])continue;
        ans[i] = 2;
        for(ll j = i*2;j<=MAXN;j+=i)ans[j]++,vis[j] = 1;
    }

    ll t;
    cin>>t;
    while(t--)
        comp();
    return 0;
}