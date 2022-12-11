#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000000,M=19;
const int mo=1e9+7;
int fir[N+10],prime[N+10],len,w[N+10][21],inv[21];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
void make(){
	len=0;
	for (int i=2;i<=N;i++){
		if (fir[i]==0){
			fir[i]=i; prime[++len]=i;
		}
		for (int j=1;j<=len&&prime[j]*i<=N;j++){
			fir[prime[j]*i]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
	int pre=1;
	w[0][0]=1; for (int i=1;i<=M;i++) w[0][i]=2;
	for (int i=1;i<=N;i++){
		w[i][0]=w[i-1][0];
		for (int j=1;j<=M;j++) w[i][j]=(w[i][j-1]+w[i-1][j])%mo;
	}
}
int getans(int k1,int r){
	int ans=1;
	while (k1!=1){
		int k=fir[k1],k2=0;
		while (fir[k1]==k){
			k2++; k1/=k;
		}
		ans=1ll*ans*w[r][k2]%mo;
	//	cout<<"asd "<<r<<" "<<k2<<" "<<w[r][k2]<<endl;
	}
	return ans;
}
int main(){
	make();
	int k1; scanf("%d",&k1);
	for (;k1;k1--){
		int k2,k3; scanf("%d%d",&k2,&k3);
		printf("%d\n",getans(k3,k2));
	}
	return 0;
}