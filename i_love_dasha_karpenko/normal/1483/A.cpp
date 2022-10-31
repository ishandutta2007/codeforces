#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
int cnt[2][N],vis[N];
vector<int> can[N],days[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;++i){
        int k;
        cin>>k;
        can[i].resize(k);
        for(int j = 0;j<k;++j){
            cin>>can[i][j];
            cnt[k!=1][can[i][j]]++;
            days[can[i][j]].push_back(i);
        }
    }
    int big = 0,flag = 0;
    int mx = (m>>1)+(m&1);
    for(int i = 1;i<=n;++i){
        if (cnt[0][i]+cnt[1][i]>mx){
            flag = 1;
            if (cnt[0][i]<=mx){
                big = i;
                break;
            }
        }
    }
    if (flag){
        if (big){
            cout<<"YES\n";
            for(int to:days[big])
                vis[to] = 1;
            int cur = cnt[0][big]+cnt[1][big];
            for(int i = 1;i<=m;++i){
                if (!vis[i]){
                    cout<<can[i][0]<<' ';
                }
                else if (cur>mx && can[i].size()!=1){
                    for(int to:can[i]){
                        if (to!=big){
                            cout<<to<<' ';
                            break;
                        }
                    }
                    --cur;
                }
                else{
                    cout<<big<<' ';
                }
            }
            assert(cur==mx);
            cout<<endl;
        }
        else{
            cout<<"NO\n";
        }
    }
    else{
        cout<<"YES\n";
        for(int i = 1;i<=m;++i)
            cout<<can[i][0]<<' ';
        cout<<endl;
    }
    for(int i = 1;i<=n;++i){
        cnt[0][i] = cnt[1][i] = 0;
        days[i].clear();
    }
    for(int i = 1;i<=m;++i){
        can[i].clear();
        vis[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}