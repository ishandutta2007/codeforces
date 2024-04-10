#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mo=1e9+7;
int K,p,pd[1100000],num[1100000],f[1100000];
int dfs(int k){
	int num=0;
	while (pd[k]==0){
		pd[k]=1; k=1ll*k*K%p; num++;
	}
	return num;
}
int main(){
	scanf("%d%d",&p,&K);
	if (K==0){
		int ans=1;
		for (int i=1;i<p;i++) ans=1ll*ans*p%mo;
		cout<<ans<<endl;
	} else {
		int ans=1;
		for (int i=0;i<p;i++) if (pd[i]==0){
			int k1=dfs(i); num[k1]++; f[k1]+=k1;
		}
		for (int i=p;i;i--)
			for (int j=i+i;j<=p;j+=i) f[j]+=f[i];
	//	for (int i=1;i<=p;i++) cout<<f[i]<<" "; cout<<endl;
		for (int i=1;i<=p;i++) 
			for (int j=1;j<=num[i];j++) ans=1ll*ans*f[i]%mo;
		cout<<ans<<endl;
	}
	return 0;
}