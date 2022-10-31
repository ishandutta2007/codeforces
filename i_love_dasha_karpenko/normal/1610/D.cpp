//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;
const int N = 2e5+7;
const int MOD = 1e9+7;
const int LOG = 35;
int cnt[LOG];
ll po[N];
void solve(){

    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        int num;
        cin>>num;
        for(int bit = 0;bit<LOG;++bit)
            if (num&(1ll<<bit)){
                ++cnt[bit];
                break;
            }
    }
    ll res = 0,sum = 0;
    for(int bit = LOG-1;bit>0;--bit){
        res+=(po[sum]*(po[max(0,cnt[bit]-1)]-1ll))%MOD;
        if (res>=MOD)
            res-=MOD;
        while (res<0)
            res+=MOD;
        sum+=cnt[bit];
    }
    res+=(po[sum]*(po[cnt[0]]-1ll))%MOD;
    if (res>=MOD)
        res-=MOD;
    while (res<0)
        res+=MOD;
    cout<<res<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    po[0] = 1;
    for(int i = 1;i<N;++i)
        po[i] = (po[i-1]<<1)%MOD;
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}