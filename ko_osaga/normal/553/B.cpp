#include <cstdio> 
typedef long long lint;

int n;
lint l;
lint dp[60];

int vis[105];

void solve(int pos, lint k){
    if(pos > n) return;
    if(dp[pos+1] < k){
        printf("%d %d ",pos+1,pos);
        solve(pos+2,k - dp[pos+1]);
    }
    else{
        printf("%d ",pos);
        solve(pos+1,k);
    }
}

int main(){
    scanf("%d %lld",&n,&l);
    dp[n+1] = 1;
    for (int i=n; i; i--) {
        dp[i] = dp[i+1] + dp[i+2];
        if(dp[i] > l) dp[i] = l + 1;
    }
    solve(1,l);
}