#include<bits/stdc++.h>
using namespace std;
const int M=5009;
int n,m;
int tr[M],rk[M],hk[M],se[M],he[M],s[M];
char c[M];
int h[M][M],dp[M];
void csort(){
	for(int i=1;i<=m;++i)tr[i]=0;
	for(int i=1;i<=n;++i)tr[rk[i]]++;
	for(int i=1;i<=m;++i)tr[i]+=tr[i-1];
	for(int i=n;i>=1;--i)hk[tr[rk[se[i]]]--]=se[i];
}
void suffix(){
	m=200;
	for(int i=1;i<=n;++i)rk[i]=c[i],se[i]=i;
	csort();
	for(int w=1,q=0;q<n;w<<=1,m=q){
		q=0;
		for(int i=1;i<=w;++i)se[++q]=n-i+1;
		for(int i=1;i<=n;++i)if(hk[i]>w)se[++q]=hk[i]-w;
		csort();q=0;
		memcpy(tr,rk,sizeof(rk));
		for(int i=1;i<=n;++i){
			rk[hk[i]]=(tr[hk[i]]==tr[hk[i-1]]&&hk[i]+w<=n&&hk[i-1]+w<=n&&tr[hk[i]+w]==tr[hk[i-1]+w])?q:++q;
		}
	}
	for(int i=1,k=0,j;i<=n;++i){
		if(k)k--;
		j=hk[rk[i]-1];
		while(c[i+k]==c[j+k])k++;
		he[rk[i]]=k;
	}
}

void work(){
	scanf("%d%s",&n,c+1);
	suffix();
	for(int i=1;i<=n;++i)dp[i]=0;
	for(int i=1;i<n;++i){
		h[i][i+1]=he[i+1];
		for(int j=i+2;j<=n;++j){
			h[i][j]=min(h[i][j-1],he[j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<rk[i];++j){
			dp[i]=max(dp[i],dp[hk[j]]+n-i+1-h[j][rk[i]]);
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}