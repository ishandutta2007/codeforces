#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-')fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const int maxn=200010;
int i,j,k,k1,k2,opt;
int l[maxn*4],r[maxn*4],dp[maxn*4][3][2][2][2][2],tot[maxn*4][3];
int n,m,x,y,ans;
int a[maxn];
char c=' ';
void merge(int x){
	int i,j,k,k1,k2;
	memset(dp[x],0,sizeof(dp[x]));
	for (i=0;i<=2;i++){
		for (j=0;j<=1;j++){
			for (k=0;k<=1;k++){
				for (k1=0;k1<=1;k1++){
					for (k2=0;k2<=1;k2++){
						dp[x][i][j][k][k1|(tot[x*2+1][(i+1)%3]!=0)][k2|(tot[x*2+1][(i+2)%3]!=0)]+=dp[x*2][i][j][k][k1][k2];
						dp[x][i][j|(tot[x*2][(i+1)%3]!=0)][k|(tot[x*2][(i+2)%3]!=0)][k1][k2]+=dp[x*2+1][i][j][k][k1][k2];
					}
				}
			}
		}
		tot[x][i]=tot[x*2][i]+tot[x*2+1][i];
	}
}
void build(int x,int ll,int rr){
	int mid=(ll+rr)>>1;
	l[x]=ll; r[x]=rr;
	if (ll==rr){
		tot[x][0]=0; tot[x][1]=0; tot[x][2]=0;
		memset(dp[x],0,sizeof(dp[x]));
		dp[x][a[ll]][0][0][0][0]=1;
		tot[x][a[ll]]++;
		return;
	}
	build(x*2,ll,mid);
	build(x*2+1,mid+1,rr);
	merge(x);
}
void changge(int x,int thi,int w){
	if (l[x]==r[x]){
		tot[x][0]=0; tot[x][1]=0; tot[x][2]=0;
		memset(dp[x],0,sizeof(dp[x]));
		dp[x][w][0][0][0][0]=1;
		tot[x][w]++;
		return;
	}
	if (thi<=r[x*2]) changge(x*2,thi,w);
	else changge(x*2+1,thi,w);
	merge(x);
}
int main(){
	n=read(); m=read();
	while ((c<'A')||(c>'Z')) c=getchar();
	for (i=1;i<=n;i++){
		if (c=='R') a[i]=0;
		if (c=='S') a[i]=1;
		if (c=='P') a[i]=2;
		c=getchar();
	}
	build(1,1,n);
	ans=0;
	for (i=0;i<=2;i++){
		for (j=0;j<=1;j++){
			for (k=0;k<=1;k++){
				for (k1=0;k1<=1;k1++){
					for (k2=0;k2<=1;k2++){
						if ((j>=k)&&(k1>=k2)){
							ans=ans+dp[1][i][j][k][k1][k2];
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	for (opt=1;opt<=m;opt++){
		x=read();
		while ((c<'A')||(c>'Z')) c=getchar();
		if (c=='R') y=0;
		if (c=='S') y=1;
		if (c=='P') y=2;
		changge(1,x,y);
		ans=0;
		for (i=0;i<=2;i++){
			for (j=0;j<=1;j++){
				for (k=0;k<=1;k++){
					for (k1=0;k1<=1;k1++){
						for (k2=0;k2<=1;k2++){
							if ((j>=k)&&(k1>=k2)){
								ans=ans+dp[1][i][j][k][k1][k2];
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		c=getchar();
	}
	return 0;
}