#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define int long long 

long long prime[1000001],top,t,factop;
long long stat[1048576],cnt,fac[2][1000001],val[101];
long long n1,n2,n3,n,m1,m2,m3,m,s1,s2,s3,s,ans1,ans2;
bool pri[1000001];
void factorize(long long x,long long *a,long long *b,long long &tp){
	tp=0;
	for(int i=1;i<=top;i++){
		++tp;
		a[tp]=prime[i];
		b[tp]=0;
		while(x%prime[i]==0)x/=prime[i],++b[tp];
		if(!b[tp])--tp;
	}
}
void dfs(int x,long long prod){
	if(prod>n)return;
	if(x>factop){
		++ans2;
		return;
	} 
	dfs(x+1,prod);
	for(int i=1;i<=fac[1][x];i++){
		prod*=fac[0][x];
		dfs(x+1,prod);
	}
}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
signed main(){
//	freopen("CF819C.in","r",stdin);
//	freopen("CF819C.out","w",stdout); 
	for(int i=2;i<=1000000;i++){
		if(!pri[i])prime[++top]=i;
		for(int j=1;j<=top&&1ll*i*prime[j]<=1000000ll;j++){
			pri[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	scanf("%I64d",&t);
	for(int i=1;i<=t;i++){
		ans1=ans2=0;
		std::cin>>n1>>n2>>n3>>m1>>m2>>m3>>s1>>s2>>s3;
		n=n1*n2*n3;
		m=m1*m2*m3;
		s=s1*s2*s3*2ll;
//		for(int i=1;i<=n;i++){
//			if(s%i==0)ans2++;
//		}
//		for(int i=1;i<=m;i++){
//			if(s%std::__gcd(n,1ll*i)==0)ans1++;
//		}
		factorize(s,fac[0],fac[1],factop);
		dfs(1,1);
		cnt=0;
		for(int i=1;i<=top;i++){
			int tem1=0,tem2=0;
			while(n%prime[i]==0)n/=prime[i],++tem1;
			while(s%prime[i]==0)s/=prime[i],++tem2;
			if(tem1>tem2){
				val[++cnt]=qsm(prime[i],tem2+1);
			}
		}
		stat[0]=1;
		for(int i=0;i<1<<cnt;i++){
			(__builtin_popcount(i)%2==1)?(ans1-=m/stat[i]):(ans1+=m/stat[i]);
			for(int j=1;j<=cnt;j++)
				if(!(i&(1<<(j-1))))stat[i|(1<<(j-1))]=stat[i]*val[j];
		}
		printf("%I64d\n",ans1+ans2);
	}
}