#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct bian{
	int next,point;
}b[210000];
int len,p[110000],n,x[110000],where[110000],where2[110000];
long long fir[110000],se[110000],thi[110000],dp1[110000],dp2[110000],ans,f[110000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void update(int k1,int k2,long long k3){
	if (k3>fir[k1]){
		thi[k1]=se[k1]; 
		se[k1]=fir[k1]; where2[k1]=where[k1];
		fir[k1]=k3; where[k1]=k2;
	} else if (k3>se[k1]){
		thi[k1]=se[k1]; se[k1]=k3; where2[k1]=k2;
	} else if (k3>thi[k1]) thi[k1]=k3;
}
void dfs(int k1,int k2){
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			dfs(j,k1); update(k1,j,fir[j]+x[j]);
		}
	}
}
void getans(int k1,int k2){
	long long num1=0,num2=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			getans(j,k1);
			if (dp1[j]>num1){
				num2=num1; num1=dp1[j];
			} else if (dp1[j]>num2) num2=dp1[j];
			ans=max(ans,fir[k1]+se[k1]+x[k1]+dp2[j]);
			if (j==where[k1]) ans=max(ans,se[k1]+thi[k1]+x[k1]+dp1[j]);
			else if (j==where2[k1]) ans=max(ans,fir[k1]+thi[k1]+x[k1]+dp1[j]);
			else ans=max(ans,fir[k1]+se[k1]+x[k1]+dp1[j]);
			if (j==where[k1]) f[k1]=max(f[k1],dp1[j]+se[k1]+x[k1]);
			else f[k1]=max(f[k1],dp1[j]+fir[k1]+x[k1]);
			f[k1]=max(f[k1],f[j]+x[k1]);
			if (j==where[k1]) ans=max(ans,f[j]+x[k1]+se[k1]);
			else ans=max(ans,f[j]+x[k1]+fir[k1]);
			dp1[k1]=max(dp1[k1],dp1[j]);
			if (j!=where[k1]) dp2[k1]=max(dp2[k1],dp1[j]);
			else dp2[k1]=max(dp2[k1],dp2[j]);
		}
	}
	ans=max(ans,num1+num2);
	f[k1]=max(f[k1],max(dp1[k1],dp2[k1]));
	dp1[k1]=max(dp1[k1],fir[k1]+se[k1]+x[k1]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	dfs(1,0); ans=0; getans(1,0);
	printf("%I64d\n",ans);
	return 0;
}