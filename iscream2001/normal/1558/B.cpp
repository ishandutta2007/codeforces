#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
LL P=998244353;
const int INF=1e9+5;
const int N=110;
int n;
int f[4000005];
void init(){
	return;
}
void MAIN(){
	scanf("%d%lld",&n,&P);
	LL G=0,S=1;
	for(int i=1;i<=n;++i) f[i]=1;
	for(int i=2;i<=n;++i){
		f[i]+=G;
		if(f[i]>=P) f[i]-=P;
		G=f[i];
		//cout<<i<<" "<<G<<endl; 
		f[i]+=S;
		if(f[i]>=P) f[i]-=P;
		S+=f[i];
		if(S>=P)S-=P;
		for(int j=i+i,k=2;j<=n&&k<=i;j+=i,++k){
			f[j]+=f[k];
			if(f[j]>=P)f[j]-=P;
			f[j]-=f[k-1];
			if(f[j]<0) f[j]+=P;
			if(k!=i){
				f[j]+=f[i];
				if(f[j]>=P)f[j]-=P;
				f[j]-=f[i-1];
				if(f[j]<0) f[j]+=P;
			}
		}
	}
	//for(int i=1;i<=n;++i) cout<<f[i]<<" ";cout<<endl;
	printf("%d\n",f[n]);
	return;
} 

int main(){
	init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}
/*

*/