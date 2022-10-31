#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2000+7;
int P[2][N],A[N][2],dp[2][N][N];
vector<int> G[2][N];
int cnt,sz[2][N],cur[N],ans[N];

void del(int v,int type){
    if (cur[v]==0){
        if (P[type][v]==0)
            return;
        ++cnt;
        cur[P[type][v]]--;
        del(P[type][v],type);
    }
}
void solve(){
    int n;
    cin>>n;
    int a[2];
    for(int c = 0;c<2;++c){
        cin>>a[c];
        for(int i = 2;i<=a[c];++i){
            cin>>P[c][i];
            sz[c][P[c][i]]++;
        }
        for(int i = 1;i<=n;++i){
            cin>>A[i][c];
        }
    }
    for(int c = 0;c<2;++c){

        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=a[c];++j)
                cur[j] = sz[c][j];
            cnt = 0;
            for(int j = i;j<=n;++j){
                del(A[j][c],c);
                dp[c][i][j] = cnt;
            }
        }
    }
    for(int i = 1;i<=n;++i){
        ans[i] = 0;
        for(int j = i;j>=1;--j){
            ans[i] = max(ans[i],ans[j-1]+max(dp[0][j][i],dp[1][j][i]));
        }
    }
    cout<<ans[n]<<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    //cin>>t;
    t = 1;
    while(t--)
        solve();
    return 0;
}