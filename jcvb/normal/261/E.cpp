#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int l,r,k;
int bo[105]={0};
int p[105]={0};int ptot=0;
int a[3000000];int tot=0;
int dis[3000000];
int f[3000000],mi[3000000];
void dfs(ll cur,int i){
	if(i==ptot)a[++tot]=cur,f[tot]=mi[tot]=100000;	
	else{
		do dfs(cur,i+1);
		while((cur*=p[i+1])<=r);
	}
}
int main()
{
	scanf("%d%d%d",&l,&r,&k);
	for (int i=2;i<=k;i++)for (int j=2*i;j<=k;j+=i)bo[j]=1;
	for (int i=2;i<=k;i++)if(!bo[i])p[++ptot]=i;
	dfs(1,0);
	sort(a+1,a+1+tot);
	f[1]=mi[1]=0;
	for (int s=2;s<k;s++){
		for (int i=1,p=1;i<=tot;i++){
			if(1ll*a[i]*s>a[tot])break;
			while(a[p]!=a[i]*s)p++;
			f[p]=min(f[p],f[i]+1);
			mi[p]=min(mi[p],f[p]+s);
		}
	}
	int ans=0;
	for (int i=1;i<=tot;i++)if(mi[i]<=k && a[i]>=l)ans++;
	printf("%d\n",ans);
	return 0;
}