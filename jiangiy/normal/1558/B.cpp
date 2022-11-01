#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=4000005;
int n,P,f[N];
LL g[N];
void add(int l,int r,int v){
	g[l]+=v;
	if(r<=n)g[r]-=v;
}
int main(){
	scanf("%d%d",&n,&P);
	int fpre=1,gpre=0;
	f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i&&i*j<=n;j++)add(i*j,i*j+i,f[j]);
		gpre=(gpre+g[i])%P;
		int t=(gpre+fpre)%P;
		if(t<0)t+=P;
		for(int j=2;j<=i&&i*j<=n;j++)add(i*j,i*j+j,t);(fpre+=f[i]=t)%=P;
	}
	printf("%d\n",f[n]);
}