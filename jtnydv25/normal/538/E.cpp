#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sd(x) scanf("%d", &(x))
const int N = 2e5 + 10;
int dp[2][N];
int leaves[N];
vector<int> con[N];
void dfs(int s, int p, int parity){
    int cnt = 0;
    int sm[2] = {0, 0};
    for(int v : con[s]) if(v != p){
        cnt++; 
        dfs(v, s, parity ^ 1);
        sm[0] += dp[0][v] - 1;
        sm[1] += dp[1][v];
        leaves[s] += leaves[v];
    }
    if(!cnt){ leaves[s] = 1; dp[0][s] = dp[1][s] = 1; return;}
    if(parity == 0){
        for(int v : con[s]) if(v != p) dp[0][s] = max(dp[0][s], leaves[s] - (leaves[v] - dp[0][v]));
        dp[1][s] = sm[1];    
    }
    else{
        dp[1][s] = leaves[s];
        for(int v : con[s]) if(v != p) dp[1][s] = min(dp[1][s], dp[1][v]);
        dp[0][s] = sm[0] + 1;
    }
}
int main(){
    int n, u, v;
    sd(n);
    for(int i = 1; i < n; i++){
        sd(u); sd(v);
        con[u].pb(v);
        con[v].pb(u);
    }
    dfs(1, 0, 0);
    for(int i = 5; i >= 1; i--){
        cerr << i << " " << dp[1][i] << endl;
    }
    printf("%d %d\n", dp[0][1], dp[1][1]);
}