#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gi(x) int(x-'a'+1)
const int N = 1e5+7;
const ll base = 31;
int A[N],nxt[N][base];

vector<int> V[3];
const int SM = 250+7;
int dp[SM][SM][SM],n,q;
const int INF = 1e9;
void solve(int pos,char type){
    if (type=='-'){
        if (dp[V[0].size()][V[1].size()][V[2].size()]<=n)
            cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    if (pos==2){
        for(int i = 0;i<=V[0].size();++i){
            for(int j = 0;j<=V[1].size();++j){
                int h = V[pos].size();
                dp[i][j][h] = INF;
                if (i>0 && dp[i-1][j][h]<=n)
                    dp[i][j][h] = min(dp[i][j][h],nxt[dp[i-1][j][h]][V[0][i-1]]);
                if (j>0 && dp[i][j-1][h]<=n)
                    dp[i][j][h] = min(dp[i][j][h],nxt[dp[i][j-1][h]][V[1][j-1]]);
                if (h>0 && dp[i][j][h-1]<=n)
                    dp[i][j][h] = min(dp[i][j][h],nxt[dp[i][j][h-1]][V[2][h-1]]);
            }
        }
    }
    if (pos==1){
        for(int i = 0;i<=V[0].size();++i){
            int j = V[1].size();
            for(int h = 0;h<=V[2].size();++h){
                dp[i][j][h] = INF;
                if (i>0 && dp[i-1][j][h]<=n)
                    dp[i][j][h] = min(dp[i][j][h],nxt[dp[i-1][j][h]][V[0][i-1]]);
                if (j>0 && dp[i][j-1][h]<=n)
                    dp[i][j][h] = min(dp[i][j][h],nxt[dp[i][j-1][h]][V[1][j-1]]);
                if (h>0 && dp[i][j][h-1]<=n)
                    dp[i][j][h] = min(dp[i][j][h],nxt[dp[i][j][h-1]][V[2][h-1]]);
            }
        }
    }
    if (pos==0){
        int i = V[0].size();
        for(int j = 0;j<=V[1].size();++j){
            for(int h = 0;h<=V[2].size();++h){
                dp[i][j][h] = INF;
                if (i>0 && dp[i-1][j][h]<=n)
                    dp[i][j][h] = min(dp[i][j][h],nxt[dp[i-1][j][h]][V[0][i-1]]);
                if (j>0 && dp[i][j-1][h]<=n)
                    dp[i][j][h] = min(dp[i][j][h],nxt[dp[i][j-1][h]][V[1][j-1]]);
                if (h>0 && dp[i][j][h-1]<=n)
                    dp[i][j][h] = min(dp[i][j][h],nxt[dp[i][j][h-1]][V[2][h-1]]);
            }
        }
    }
    if (dp[V[0].size()][V[1].size()][V[2].size()]<=n)
        cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = gi(ch);
    }
    for(int j = 0;j<base;++j)
        nxt[n+1][j] = INF;
    for(int i = n;i>=0;--i){
        for(int j = 0;j<base;++j)
            nxt[i][j] = nxt[i+1][j];
        if (i<n)
            nxt[i][A[i+1]] = i+1;
    }


    while(q--){
        char type;
        cin>>type;
        int pos;
        cin>>pos;
        --pos;
        if (type=='+'){
            char ch;
            cin>>ch;
            V[pos].push_back(gi(ch));
        }
        else{
            V[pos].pop_back();
        }
        solve(pos,type);
    }

    return 0;
}