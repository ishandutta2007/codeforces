#include <bits/stdc++.h>
#define int long long

long long f[1000001];
int k,F[6];
void add(int siz,long long val){
	for(int i=999999;i>=siz;i--)
		f[i]=std::max(f[i],f[i-siz]+val);
}
signed main(){
	scanf("%lld",&k);
	for(int i=0;i<6;i++)scanf("%lld",F+i);
	memset(f,-0x7f7f7f7f,sizeof f);
	f[0]=0;
	int l=1,res=(k-1)*3;
	while(l<=res){
		for(int i=0,Mul=3*l;i<6;i++,Mul*=10){
			add(Mul,l*F[i]);
		}
		res-=l;
		l<<=1;
	}
	for(int i=0,Mul=3*res;i<6;i++,Mul*=10){
		add(Mul,res*F[i]);
	}
	for(int i=0,Mul=1;i<6;i++,Mul*=10){
		for(int j=999999;j;--j)
			for(int k=0;k<10&&Mul*k<=j;k++)
				f[j]=std::max(f[j],f[j-Mul*k]+(k%3==0)*(k/3*F[i]));
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int x;
		scanf("%d",&x);
		printf("%lld\n",f[x]);
	}
}