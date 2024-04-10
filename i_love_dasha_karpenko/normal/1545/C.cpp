#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 1E3+7;
int A[DIM][DIM/2],cnt[DIM/2][DIM/2],re[DIM/2][DIM/2];
int vis[DIM];
const int MOD = 998244353;
int solve() {
    int n;
    cin>>n;
    for(int i = 1;i<=n*2;++i){
        for(int j = 1;j<=n;++j) {
            cin >> A[i][j];
            cnt[j][A[i][j]]++;
        }
    }
    int res = 1;
    vector<int> V;
    while(1){
        int cur = 0,fl = 0;
        for(int i = 1;i<=n*2;++i){
            if (vis[i])
                continue;
            cur = i;
            int flag = 0;
            for(int j = 1;j<=n;++j){
                if (cnt[j][A[i][j]]==1)
                    flag = 1;
            }
            if (flag==1) {
                cur = i;
                fl = 1;
                break;
            }
        }
        if (cur==0)
            break;
        if (fl==0)
            res*=2;
        if (res>=MOD)
            res-=MOD;
        V.push_back(cur);
        for(int j = 1;j<=n;++j){
            re[j][A[cur][j]] = 1;
        }
        for(int i = 1;i<=n*2;++i){
            if (vis[i])
                continue;
            int no = 0;

            for(int j = 1;j<=n;++j){
                if (re[j][A[i][j]])
                {
                    no = 1;
                    break;
                }
            }
            if (!no)
                continue;
            vis[i] = 1;
            for(int j = 1;j<=n;++j){
                cnt[j][A[i][j]]--;
            }
        }
    }
   // reverse(V.begin(),V.end());
    cout<<res<<endl;
    for(auto to:V)
        cout<<to<<' ';
    cout<<endl;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=n;++j)
            re[i][j] = cnt[i][j] = 0;
    memset(vis,0,sizeof(vis));
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        assert(solve());
}