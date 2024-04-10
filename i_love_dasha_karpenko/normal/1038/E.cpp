//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'0')
int mi[4][4],cnt[4][4];
int deg[4],vis[4];
ll es[4];
pair<ll,int> dfs(int a){
    vis[a] = 1;
    ll sum = es[a];
    int odd = deg[a]&1;
    for(int b = 0;b<4;++b){
       if (vis[b]==0 && (cnt[a][b] || cnt[b][a])) {
           auto ret = dfs(b);
           sum+=ret.first;
           odd+=ret.second;
       }
    }
    return {sum,odd};
}
void solve(){
    int n;
    cin>>n;
    ll sum = 0;
    for(int i = 1;i<=n;++i){
        int c1,val,c2;
        cin>>c1>>val>>c2;
        --c1;
        --c2;
        if (c1>c2)
            swap(c1,c2);
        if (mi[c1][c2]==0)
            mi[c1][c2] = val;
        mi[c1][c2] = min(mi[c1][c2],val);
        ++deg[c1];
        ++deg[c2];
        es[c1]+=val;
        es[c2]+=val;
        cnt[c1][c2]++;
        sum+=val;
    }
    ll res = 0;
    int sz = 1<<16;
    for(int mask = 0;mask<sz;++mask){
        ll su = sum;
        int flag = 0;
        for(int bit = 0;bit<16;++bit){
            if (mask&(1<<bit)){
                int a = bit>>2,b = bit&3;
                if (!cnt[a][b]){
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            continue;
        for(int bit = 0;bit<16;++bit){
            if (mask&(1<<bit)){
                int a = bit>>2,b = bit&3;
                --deg[a];
                --deg[b];
                es[a]-=mi[a][b];
                es[b]-=mi[a][b];
                su-=mi[a][b];
                cnt[a][b]--;
            }
        }
        memset(vis,0,sizeof(vis));
        for(int c = 0;c<4;++c){
            if (!deg[c])
                continue;
            if (!vis[c]) {
                auto ret = dfs(c);
                if (ret.second<=2)
                    res = max(res,ret.first>>1);
            }
        }
        for(int bit = 0;bit<16;++bit){
            if (mask&(1<<bit)){
                int a = bit>>2,b = bit&3;
                ++deg[a];
                ++deg[b];
                es[a]+=mi[a][b];
                es[b]+=mi[a][b];
                //su-=mi[a][b];
                cnt[a][b]++;
            }
        }

    }
    cout<<res<<endl;
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