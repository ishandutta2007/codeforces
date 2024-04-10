#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mo=1e9+7;
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int I[210000],nI[210000],n,m,K,S,dp[2100][30],go[2100][2100],ans[50],w[50];
int lim=25;
struct atom{
	int x,y;
}x[3000];
int compare(atom k1,atom k2){
	return k1.x+k1.y<k2.x+k2.y;
}
int C(int k1,int k2){
	return 1ll*I[k1]*nI[k2]%mo*nI[k1-k2]%mo;
}
int get(int k1,int k2){
	if (k1<0||k2<0) return 0;
	return C(k1+k2,k1);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&K,&S);
	I[0]=1; for (int i=1;i<=n+m;i++) I[i]=1ll*I[i-1]*i%mo;
	nI[0]=1; for (int i=1;i<=n+m;i++) nI[i]=quick(I[i],mo-2);
	for (int i=1;i<=K;i++) scanf("%d%d",&x[i].x,&x[i].y);
	sort(x+1,x+K+1,compare);
	for (int i=1;i<=K;i++) dp[i][1]=-get(x[i].x-1,x[i].y-1),dp[i][0]=-get(x[i].x-1,x[i].y-1);
	for (int i=1;i<=K;i++)
		for (int j=i+1;j<=K;j++)
			go[i][j]=get(x[j].x-x[i].x,x[j].y-x[i].y);
/*	for (int i=1;i<=K;i++){
		for (int j=0;j<=5;j++) cout<<dp[i][j]<<" "; cout<<endl;
	}*/
	for (int i=1;i<=K;i++)
			for (int j=i+1;j<=K;j++)
				if (go[i][j])
		for (int k=0;k<=lim;k++){
					int num=dp[i][k];
					if (k) num=(num+1ll*k*dp[i][k-1])%mo; 
				//	cout<<"go "<<k<<" "<<go[i][j]<<" "<<num<<endl;
					num=1ll*num*(-go[i][j])%mo;
					dp[j][k]=(dp[j][k]+num)%mo;
				}
	ans[0]=get(n-1,m-1);
	for (int i=1;i<=K;i++)
		for (int j=0;j<=lim;j++){
			int num=1ll*dp[i][j]*get(n-x[i].x,m-x[i].y)%mo;
			ans[j]=(ans[j]+num)%mo;
		}
	for (int i=0;i<=lim;i++){
		w[i]=1ll*ans[i]*nI[i]%mo;
		if (i&1) w[i]=-w[i];
	}
	/*for (int i=1;i<=K;i++) cout<<"fa "<<x[i].x<<" "<<x[i].y<<endl;
	for (int i=1;i<=K;i++){
		for (int j=0;j<=5;j++) cout<<dp[i][j]<<" "; cout<<endl;
	}*/
	w[lim+1]=get(n-1,m-1);
	for (int i=0;i<=lim;i++) w[lim+1]=(w[lim+1]-w[i])%mo;
	//for (int i=0;i<=lim;i++) cout<<w[i]<<" "; cout<<endl;
	int ans=0;
	for (int i=0;i<=lim+1;i++){
		ans=(ans+1ll*w[i]*S)%mo;
		S=(S+1)/2;
	}
	ans=1ll*ans*quick(get(n-1,m-1),mo-2)%mo;
	printf("%d\n",(ans+mo)%mo);
	return 0;
}