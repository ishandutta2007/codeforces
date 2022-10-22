#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,ans,a[11][1100],pos[11][1100],dp[1100];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
		for (int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			pos[i][a[i][j]]=j;
		}
	for (int i=1;i<=n;i++){
		dp[i]=1;
		for (int j=1;j<i;j++){
            bool flag=true;
            for (int t=2;t<=k;t++)
                if (pos[t][a[1][j]]>pos[t][a[1][i]]){ flag=false; break;}
            if (flag) dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}