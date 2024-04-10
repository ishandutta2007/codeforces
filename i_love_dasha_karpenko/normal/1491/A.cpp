//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
const ll INF = 1E18;
const ll MAXN = 1E6+1;
ll A[DIM];
ll solve(){
    ll n,q;
    cin>>n>>q;
    ll cnt[] = {0,0};
    for(ll i = 1;i<=n;++i){
        ll x;
        cin>>x;
        A[i] = x;
        cnt[x]++;
    }
    while(q--){
        ll t;
        cin>>t;
        if (t==1){
            ll x;
            cin>>x;
            cnt[A[x]]--;
            cnt[A[x]^1]++;
            A[x]^=1;
        }
        else{
            ll x;
            cin>>x;
            if (cnt[1]>=x)cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    while(t--)
        solve();

    return 0;
}