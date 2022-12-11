#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct bian{
	int next,point;
}b[210];
int dp[110][25][25],p[110],len,n,K,size[110],A[25][25];
const int mo=1e9+7;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
int get2(int k1,int k2){
	return max(k1,k2);
}
int get1(int k1,int k2){
	if (k1==0||k2==0) return k1+k2;
	return min(k1,k2);
}
void addd(int &k1,int k2){
	k1=(k1+k2)%mo;
}
void merge(int k1,int k2){
	memset(A,0x00,sizeof A);
	for (int i=0;i<=size[k1];i++)
		for (int j=0;j<=size[k1];j++){
			if (dp[k1][i][j]==0) continue;
			for (int a=0;a<=size[k2];a++)
				for (int b=0;b<=size[k2];b++){
					if ((b&&b+1>K)||dp[k2][a][b]==0) continue;
					//cout<<"fa "<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
					int c=a+1,d=b+1; 
					if (a==0||c>K) c=0; if (b==0) d=0;
					int e=i,f=j;
					if (i&&i+b<=K) d=0;
					if (a&&a+j<=K) f=0;
					//cout<<get1(c,e)<<" "<<get2(d,f)<<endl;
					addd(A[get1(c,e)][get2(d,f)],1ll*dp[k1][i][j]*dp[k2][a][b]%mo);
				//	cout<<get1(c,e)<<" "<<get2(d,f)<<" "<<A[get1(c,e)][get2(d,f)]<<endl;
				}
		}
	size[k1]=min(K,size[k1]+size[k2]);
	memcpy(dp[k1],A,sizeof A);
}
void treedp(int k1,int k2){
	dp[k1][0][1]=1; dp[k1][1][0]=1; size[k1]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			treedp(j,k1);
			merge(k1,j);
		/*	cout<<"ads "<<k1<<" "<<k2<<endl;
			for (int a=0;a<=K;a++){
				for (int b=0;b<=K;b++)
					cout<<dp[k1][a][b]<<" "; cout<<endl;}*/
		}
	}
}
int main(){
	scanf("%d%d",&n,&K); K++;
	if (K==0){
		printf("1\n"); return 0;
	}
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	treedp(1,0);
	int ans=0;
	for (int i=0;i<=K;i++) ans=(ans+dp[1][i][0])%mo;
	printf("%d\n",ans); return 0;
}