#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
const int INF = 1e9+7;
void solve() {
    int sz = 6;
    vector<int> V(sz);
    for(int i = 0;i<sz;++i)
        cin>>V[i];
    bool flag = 1;
    int res = 0;
    while(flag){
        int mi = INF;
        for(int i = 0;i<sz;++i)
            mi = min(mi,V[i]);
        if (mi<0)
            break;
        if (mi==0) {
            flag = 0;
            for (int i = 0; i < sz; ++i) {
                if (V[i])
                    continue;
                int pr = (i + sz - 1) % sz, nxt = (i + 1) % sz;
                int g = min(V[pr], V[nxt]);
                flag = max(flag,g>0);
                V[pr] -= g;
                V[nxt] -= g;
                V[i] += g;
                res += g*g;
            }
            continue;
        }
        else{
            for(int i = 0;i<sz;++i){
                res+=V[i]*2-1;
                V[i]--;
            }
        }
    }
    cout<<res<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}