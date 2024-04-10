#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt;
const long long mod=998244353;
long long getax(long long a,long long x){
	long long t1=1,t2=a,t3=1;
	while (x!=0){
		if (x%(t1*2)/t1==1){
			x=x-t1; t3=t3*t2%mod;
		}
		t1=t1*2; t2=t2*t2%mod;
	}
	return t3;
}
const int maxn=200010;
long long a[maxn],b[maxn];
long long st[maxn][22];
long long i,j,k;
long long n,ans,thi,r,ha[maxn];
long long gcd(long long x,long long y){
	if (x<y) swap(x,y);
	if (y==0) return x;
	return gcd(y,x%y);
}
long long getlr(int l,int r){
	int len=r-l+1;
	return gcd(st[l][ha[len]],st[r-(1<<ha[len])+1][ha[len]]);
}
int main(){
	
	j=1;
	for (i=1;i<=21;i++){
		if (j<maxn)ha[j]=i-1;
		j=j*2;
	}
	for (i=1;i<maxn;i++) if (ha[i]==0) ha[i]=ha[i-1];
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); ans=1;
		for (i=1;i<=n;i++) a[i]=read();
		for (i=1;i<n;i++) b[i]=abs(a[i]-a[i+1]);
		for (i=1;i<n;i++) st[i][0]=b[i];
		for (k=1;k<=20;k++){
			for (i=1;i<n;i++){
				st[i][k]=st[i][k-1];
				if (i+(1<<(k-1))<n) st[i][k]=gcd(st[i+(1<<(k-1))][k-1],st[i][k]);
			}
		}
		r=0; thi=b[1];
		for (i=1;i<n;i++){
			r=max(r,i-1);
			while ((r!=n-1)&&(getlr(i,r+1)>1)){
				r++;
			}
			ans=max(ans,r-i+1+1);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}