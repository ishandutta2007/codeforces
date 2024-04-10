#include<bits/stdc++.h>
using namespace std;
int n,k,a[109];
double dp[109][109],pre[109][109];
double ans=0;
int calc(int x){return x*(x+1)/2;}
void work(){
	memcpy(pre,dp,sizeof(dp));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			double x=calc(i-1)+calc(j-i-1)+calc(n-j)+min(j-i,i)+min(j-i,n-j+1);
			dp[i][j]=pre[i][j]*x/calc(n);
			for(int l=1;l<i;++l){
				dp[i][j]+=pre[l][j]*min(l,j-i)/calc(n);
			}
			for(int l=i+1;l<j;++l){
				dp[i][j]+=pre[l][j]*min(i,j-l)/calc(n);
				dp[i][j]+=pre[i][l]*min(n-j+1,l-i)/calc(n);
			}
			for(int l=j+1;l<=n;++l){
				dp[i][j]+=pre[i][l]*min(n-l+1,j-i)/calc(n);
			}
			for(int l=1;l<=n;++l){
				int r=l+j-i,y;
				if(r>n)continue;
				if(l<i)y=min(l,n-j+1);
				else y=min(i,n-r+1);
				dp[i][j]+=(1.0-pre[l][r])*y/calc(n);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	k=min(k,900);
	while(k--)work();
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[i]>a[j])ans+=1.0-dp[i][j];
			else ans+=dp[i][j];
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}