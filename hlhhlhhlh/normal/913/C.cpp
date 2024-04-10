#include<bits/stdc++.h>
using namespace std;
const long long maxn=110;
long long n,m,a[maxn],f[maxn],get2n[maxn],t1,t2,ans,tot;
long long i,j,k;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++){
		a[i]=read();
	}
	get2n[0]=1;
	for (i=1;i<=31;i++){
		get2n[i]=get2n[i-1]*2;
	}
	f[1]=a[1];
	for (i=2;i<=n;i++){
		f[i]=min(f[i-1]*2,a[i]);
	}
	for (i=1;i<=n-1;i++){
		f[i]=min(f[i],f[i+1]);
	}
	ans=8*(1e18);
	tot=0;
	for (i=n;i>=1;i--){
		if (m==0) break;
		t1=m/get2n[i-1];
		t2=m%get2n[i-1];
		if (t2!=0) t1=t1+1;
		ans=min(ans,tot+t1*f[i]);
		if (t2!=0) t1=t1-1;
		tot=tot+t1*f[i];
		m=t2;
	}
	printf("%I64d\n",ans);
	return 0;
}