#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const long long mod=1e9+7;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long getax(long long a,long long x){
	long long t1=1,t2=a,t3=1;
	while (x!=0){
		 if (x%(t1*2)/t1==1){
			x=x-t1; t3=(t3*t2)%mod;
		}
		t1=t1*2; t2=(t2*t2)%mod;
	}
	return t3;
}
long long i,j,k;
char ccc=' ';
long long l,r;
long long s[maxn],t[maxn];
long long inv[maxn],ni[maxn];
long long a,b,c,d,len,aa,bb,cc,dd;
long long x,y,z,w,ans;
long long C(long long n,long long m){
	if (n<0) return 1;
	if (m<0) return 1;
	return (((inv[n]*ni[m])%mod)*ni[n-m])%mod;
}
long long work (long long n,long long *A,long long fla){
	if (n>len){
		if ((c==0)&&((a>=1)||(b>=1))) return 0;
		return (C(a+c-1,c-1)*C(b+d,b))%mod;
	}
	if (n<len) return 0;
	aa=a; bb=b; cc=c; dd=d;
	long long ans=0;
	for (i=2;i<=n;i++){
		if (A[i]==1){
			if (A[i-1]==0) a--;
			if (A[i-1]==1) c--;
			if ((a>=0)&&(c>=0)&&(b>=0)&&(d>=0)){
				if (((d>=1)||(c>=1))&&(b==0)) ans=ans;
				else{
					if ((b-c==0)||(b-c==1)) ans=(ans+C(a+c,c)*C(b+d-1,b-1))%mod;
				}
			}
			if (A[i-1]==0) a++;
			if (A[i-1]==1) c++;
		}
		if ((A[i-1]==0)&&(A[i]==0)) a--;
		if ((A[i-1]==0)&&(A[i]==1)) b--;
		if ((A[i-1]==1)&&(A[i]==0)) c--;
		if ((A[i-1]==1)&&(A[i]==1)) d--;
	}
	if (fla==1){
		if ((a==0)&&(b==0)&&(c==0)&&(d==0)) ans=(ans+1)%mod;
	}
	a=aa; b=bb; c=cc; d=dd;
	return ans;
}
int main(){
//	freopen("i.in","r",stdin);
//	freopen("i.out","w",stdout);
	inv[0]=1; for (i=1;i<maxn;i++) inv[i]=(inv[i-1]*i)%mod;
	ni[maxn-1]=getax(inv[maxn-1],mod-2); for (i=maxn-2;i>=0;i--) ni[i]=(ni[i+1]*(i+1))%mod;
	while ((ccc<'0')||(ccc>'9')) ccc=getchar();
	while ((ccc>='0')&&(ccc<='9')){ l++; s[l]=ccc-'0'; ccc=getchar(); }
	while ((ccc<'0')||(ccc>'9')) ccc=getchar();
	while ((ccc>='0')&&(ccc<='9')){ r++; t[r]=ccc-'0'; ccc=getchar(); }
	a=read(); b=read(); c=read(); d=read();
	len=a+b+c+d+1;
	if ((c-b!=0)&&(c-b!=1)){
		printf("0\n"); return 0;
	}
	printf("%I64d\n",(work(r,t,1)-work(l,s,0)+mod)%mod);
	return 0;
}