// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
long long i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long n,d,m,l,r;
long long tot,a[maxn],mx,b[maxn];
int main(){
	
	n=read(); d=read(); m=read();
	for (i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1); n--;
	for (i=1;i<=n;i++){
		if (a[i]<=m) tot=tot+a[i];
	}
	for (i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	mx=tot;
	for (i=1;i<=n;i++) if (a[i]<=m) r=i;
	for (i=n;i>=1;i--){
		if (a[i]<=m) break;
		if ((i-1)-(n-i+1)*d<0) break;
		tot=b[n]-b[i-1];
		tot=tot+b[r]-b[r-min((i-1)-(n-i+1)*d,r)];
		mx=max(mx,tot);
	}
	
	printf("%lld\n",mx+a[n+1]);
	
	return 0;
}
/*
7 2 11
100 100 10 10 10 20 20

*/