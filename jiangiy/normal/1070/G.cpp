#include<bits/stdc++.h>
#define maxn 110
using namespace std;
int a[maxn],n,m,s[maxn],h[maxn],c[maxn];
int fa[2][maxn][maxn];
int dp[maxn],pre[maxn];
int dp2[maxn],pre2[maxn],vis[maxn];
void print(vector<int> v){
	for(int i=1;i<=m;++i)vis[i]=0;
	for(auto c:v)vis[c]=1;
	for(int i=1;i<=m;++i)if(!vis[i])
		v.push_back(i);
	for(auto c:v)printf("%d ",c);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&s[i],&h[i]);
		c[s[i]]=i;
	}
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		int sum=0,mn=0;
		for(int j=i;j<=n;++j){
			sum+=a[j];
			mn=min(mn,sum);
			fa[0][i][j]=mn;
		}
	}
	for(int i=1;i<=n;++i){
		int sum=0,mn=0;
		for(int j=i;j>=1;--j){
			sum+=a[j];
			mn=min(mn,sum);
			fa[1][i][j]=mn;
		}
	}
	int L=0,R=0;
	for(int i=1;i<=n&&!L;++i)if(c[i])L=i;
	for(int i=n;i>=1&&!R;--i)if(c[i])R=i;
	for(int i=1;i<=n;++i){
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		dp[i-1]=1,dp2[i]=1;
		for(int j=i;j<=n;++j)if(c[j])
			for(int k=j-1;k>=i-1;--k)if(fa[1][j][k+1]+h[c[j]]>=0&&dp[k])
				dp[j]|=dp[k],pre[j]=k;
		for(int j=i-1;j>=1;--j)if(c[j])
			for(int k=j+1;k<=i;++k)if(fa[0][j][k-1]+h[c[j]]>=0&&dp2[k])
				dp2[j]|=dp2[k],pre2[j]=k;
		if((L>i-1||dp2[L])&&(R<i||dp[R])){
			vector<int> v,va,vb;
			if(R>=i){
				for(int k=R;k!=i-1;k=pre[k])
					va.push_back(c[k]);
				reverse(va.begin(),va.end());
			} 
			if(L<=i-1){
				for(int k=L;k!=i;k=pre2[k])
					vb.push_back(c[k]);
				reverse(vb.begin(),vb.end());
			}
			for(auto c:va)v.push_back(c);
			for(auto c:vb)v.push_back(c);
			printf("%d\n",R<i?i-1:i);
			print(v);
			return 0;
		}
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		dp[i]=1,dp2[i+1]=1;
//		printf("[%d]",fa[1][8][7]+h[c[8]]);
		for(int j=i+1;j<=n;++j)if(c[j])
			for(int k=j-1;k>=i;--k)if(fa[1][j][k+1]+h[c[j]]>=0&&dp[k])
				dp[j]|=dp[k],pre[j]=k;//,printf("{%d,%d}",c[j],k);
		for(int j=i;j>=1;--j)if(c[j])
			for(int k=j+1;k<=i+1;++k)if(fa[0][j][k-1]+h[c[j]]>=0&&dp2[k])
				dp2[j]|=dp2[k],pre2[j]=k;
////		printf("{%d:%d,%d}<%d,%d>\n",i,dp[R],dp2[L],L,R);
		if((L>i||dp2[L])&&(R<i+1||dp[R])){
//			puts("OK");
			vector<int> va,vb,v;
			if(R>=i+1){
				for(int k=R;k!=i;k=pre[k])
					va.push_back(c[k]);
				reverse(va.begin(),va.end());
			} 
			if(L<=i){
				for(int k=L;k!=i+1;k=pre2[k])
					vb.push_back(c[k]);
				reverse(vb.begin(),vb.end());
			}
			for(auto c:vb)v.push_back(c);
			for(auto c:va)v.push_back(c);
			printf("%d\n",L>i?i+1:i);
			print(v);
			return 0;
		}
	}
	puts("-1");
}