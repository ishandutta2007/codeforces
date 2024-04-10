//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'0')
const int N = 16;
const int masksz = 1<<N;
map<pair<int,int>,int> dp[masksz];
struct card{
    char c;
    int r,b;
} A[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i)
        cin>>A[i].c>>A[i].r>>A[i].b;
    int sz = 1<<n;
    dp[0][{0,0}] = 0;
    for(int mask = 0;mask+1<sz;++mask){
        int cnt[2] = {0,0};
        for(int bit = 0;bit<n;++bit){
            if (mask&(1<<bit))
                cnt[A[bit].c!='R']++;
        }
        for(int nxt = 0;nxt<n;++nxt){
            if (mask & (1<<nxt))
                continue;
            int nmask = mask^(1<<nxt);
            for(auto [param,res]:dp[mask]){
                pair<int,int> nparam = {param.first-max(0,A[nxt].r-cnt[0]),param.second-max(0,A[nxt].b-cnt[1])};
                int g = 0;
                g = max(g,-nparam.first);
                g = max(g,-nparam.second);
                res+=g;
                nparam.first += g;
                nparam.second +=g;
                if (!dp[nmask].count(nparam))
                    dp[nmask][nparam] = res;
                dp[nmask][nparam] = min(dp[nmask][nparam],res);
            }
        }
    }
    int res = 1e9;
    for(auto [param,val]:dp[sz-1])
        res = min(res,val);
    cout<<res+n<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();

    return 0;
}