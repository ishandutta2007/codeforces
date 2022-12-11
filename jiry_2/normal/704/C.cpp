#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct bian{
	int next,point,w;
}b[210000];
int bo[110000],p[110000],n,len,m,u,v,del,pdu,pdv,pd[110000],an0,an1,tot,dp[110000][2][2];
const int mo=1e9+7;
void ade(int k1,int k2,int k3){
	b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void add(int k1, int k2,int k3,int k4){
	k1=abs(k1); k2=abs(k2);
	ade(k1,k2,k3); ade(k2,k1,k4);
}
void dfs(int k,int pre){
	tot-=2; pd[k]=1; 
	for (int i=p[k];i!=-1;i=b[i].next){
		int j=b[i].point; tot++;// cout<<"fa "<<k<<" "<<j<<" "<<pre<<endl;
		if (j==k) tot++;
		if (pd[j]==0) dfs(j,i);
		else if (i!=(pre^1)){
			u=k; v=j; del=i;// cout<<del<<endl;
		}
	}
}
int check(int k1,int k2,int k3){
	if ((k3&2)==0) k1^=1;
	if ((k3&1)==0) k2^=1;
	return (k1|k2);
}
void treedp(int k1,int k2){
	for (int i=p[k1];i!=-1;i=b[i].next){
		int j=b[i].point;
		if (j==k2||i==del||(i^1)==del) continue;
		treedp(j,k1);
	}
	memset(dp[k1],0x00,sizeof dp[k1]);
	for (int w=0;w<2;w++){
		if (k1==u&&w!=pdu) continue;
		if (k1==v&&w!=pdv) continue;
		int ans0=1,ans1=0;
		for (int i=p[k1];i!=-1;i=b[i].next){
			int j=b[i].point;
			if (j==k2||i==del||(i^1)==del) continue;
			int an0=ans0,an1=ans1; ans0=0; ans1=0;
			for (int w1=0;w1<2;w1++){
				int a=dp[j][w1][0],bb=dp[j][w1][1];
				if (check(w,w1,b[i].w))
					swap(a,bb);
				ans0=(ans0+1ll*a*an0+1ll*bb*an1)%mo;
				ans1=(ans1+1ll*a*an1+1ll*bb*an0)%mo;
			}
		}
		if (bo[k1]&(1<<w)) swap(ans0,ans1);
		dp[k1][w][0]=(dp[k1][w][0]+ans0)%mo;
		dp[k1][w][1]=(dp[k1][w][1]+ans1)%mo;
	}
/*	cout<<"asdasd "<<k1<<" "<<k2<<endl;
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++) cout<<dp[k1][i][j]<<" "; cout<<endl;}*/
}
void solve(int k){
	tot=0; del=-100;  dfs(k,-1);
	int ans0=0,ans1=0;// cout<<del<<endl;
	if (del==-100){
		v=0; u=k; pdu=0; pdv=1; del=-100;
		treedp(k,0); ans0=(ans0+1ll*dp[k][0][0]+dp[k][1][0])%mo; ans1=(ans1+1ll*dp[k][0][1]+dp[k][1][1])%mo;
		pdu=1;
		treedp(k,0); ans0=(ans0+1ll*dp[k][0][0]+dp[k][1][0])%mo; ans1=(ans1+1ll*dp[k][0][1]+dp[k][1][1])%mo;
	//	cout<<"asdasd "<<ans0<<" "<<ans1<<" "<<k<<endl;
	} else {
		for (pdu=0;pdu<2;pdu++)
			for (pdv=0;pdv<2;pdv++){
				treedp(u,0);
				if (check(pdu,pdv,b[del].w)){
					swap(dp[u][0][0],dp[u][0][1]);
					swap(dp[u][1][0],dp[u][1][1]);
				}
				ans0=(ans0+1ll*dp[u][0][0]+dp[u][1][0])%mo; ans1=(ans1+1ll*dp[u][0][1]+dp[u][1][1])%mo;
			}
	}
	int k1=an0,k2=an1;
	an0=(1ll*k1*ans0+1ll*k2*ans1)%mo;
	an1=(1ll*k2*ans0+1ll*k1*ans1)%mo;
}
int main(){
	len=-1; memset(p,0xff,sizeof p);
	scanf("%d%d",&m,&n);
	for (;m;m--){
		int k1; scanf("%d",&k1);
		if (k1==1){
			int k2; scanf("%d",&k2);
			if (k2>0) bo[k2]|=2;
			else bo[-k2]|=1;
		} else if (k1==2){
			int k2; scanf("%d%d",&k1,&k2);
			if (k1<0&&k2<0) add(k1,k2,0,0);
			if (k1<0&&k2>0) add(k1,k2,1,2);
			if (k1>0&&k2<0) add(k1,k2,2,1);
			if (k1>0&&k2>0) add(k1,k2,3,3);
		}
	}
	an0=1; an1=0;
	for (int i=1;i<=n;i++) if (pd[i]==0) solve(i);
	printf("%d\n",an1);
	return 0;
}