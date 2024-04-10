#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int qp(int a,int b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int n,m,p;
int b=0;
int di[2005],dtot=0;
int bo[2005]={0};
int t[10005];
int dp[2005]={0};
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i*i<=p-1;i++)if((p-1)%i==0){
		di[++dtot]=i;
		di[++dtot]=(p-1)/i;
		if(di[dtot]==di[dtot-1])dtot--;
	}
	sort(di+1,di+1+dtot);
	for (int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		for (int j=1;j<=dtot;j++)if(qp(x,di[j],p)==1){
			t[i]=(p-1)/di[j];
			break;
		}
	}
	for (int i=1;i<=m;i++){
		int x;scanf("%d",&x);
		b=gcd(b,x);
	}b=gcd(b,p-1);
	p=(p-1)/b;
	for (int i=1;i*i<=p;i++)if(p%i==0){
		di[++dtot]=i;
		di[++dtot]=p/i;
		if(di[dtot]==di[dtot-1])dtot--;
	}
	sort(di+1,di+1+dtot);
	for (int i=1;i<=n;i++){
		t[i]=gcd(t[i],p);
		bo[lower_bound(di+1,di+1+dtot,t[i])-di]=1;
	}
	for (int i=1;i<=dtot;i++)if(bo[i]){
		for (int j=dtot;j>=1;j--)if(dp[j])dp[lower_bound(di+1,di+1+dtot,lcm(di[i],di[j]))-di]-=dp[j];
		dp[i]++;
	}
	int ans=0;
	for (int i=1;i<=dtot;i++)ans+=dp[i]*(p/di[i]);
	printf("%d\n",ans);
	return 0;
}