#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
using namespace std;
int dp[205][405];
int a[205];
const int inf = 0x3f3f3f3f;
int main(){
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        fors(i,1,n+1) scanf("%d", &a[i]);
        sort(a+1,a+n+1);
        fors(i,1,n+1){
            dp[i][0] = inf;
            for(int t = 1; t < 405; ++t){
                dp[i][t] = inf;
                for(int pre = 0; pre < t; ++pre){
                    dp[i][t] = min(dp[i][t], dp[i-1][pre] + abs(a[i]-t));
                }
                //if(dp[i][t] <= 15) cout<<"i:"<<i<<" t:"<<t<<" "<<dp[i][t]<<endl;
            }
        }
        int ans = inf;
        fors(i,1,405) ans = min(ans, dp[n][i]);
        printf("%d\n", ans);
    }
}