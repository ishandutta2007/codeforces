#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N=5000+10;
ll a[N],dp[N][N],ans=-1e18;
deque <int> q;

int main(){
    int n,k,x;
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    dp[i][j]=-1e18;
    dp[0][0]=0;
    for(int j=1;j<=x;j++){
        q.push_back(0);
        for(int i=1;i<=n;i++){
            while(!q.empty()&&q.front()<i-k) q.pop_front();
            dp[i][j]=dp[q.front()][j-1]+a[i];
            while(!q.empty()&&dp[q.back()][j-1]<=dp[i][j-1]) q.pop_back();
            q.push_back(i);
        }
        q.clear();
    }

    for(int i=n-k+1;i<=n;i++) ans=max(ans,dp[i][x]);
    if(ans<0) ans=-1;

    printf("%lld\n",ans);
    return 0;
}