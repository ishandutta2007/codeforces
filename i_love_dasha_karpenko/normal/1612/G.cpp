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
const int N = 5e5+7;
const int SZ = 1e6+7;
const ll MOD = 1e9+7;
ll fact[SZ];
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int> > events;
    for(int i = 1;i<=n;++i){
        int c;
        cin>>c;

        events.push_back({-c+1, 1});
        events.push_back({c+1, -1});

    }
    sort(all(events));
    int ptr = 0;
    int cnt[2] = {0,0};
    ll res = 0;
    ll perms = 1;
    ll cur = 0;
    for(int w = -SZ;w<SZ;++w){
        while (ptr<events.size() && events[ptr].first==w){
            int odd = abs(events[ptr].first)&1;
            cnt[odd]+=events[ptr].second;
            ++ptr;
        }
        ll total = cnt[w&1];
        if (!total)
            continue;
        perms = (perms*fact[total])%MOD;
        res += (cur*total+total*(total+1)*2)%MOD*w%MOD;
        cur+=total;
        while (res<0)
            res+=MOD;
        while(res>=MOD)
            res-=MOD;
    }
    cout<<res<<' '<<perms<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0] = 1;
    for(int i = 1;i<SZ;++i)
        fact[i] = fact[i-1]*i%MOD;
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}