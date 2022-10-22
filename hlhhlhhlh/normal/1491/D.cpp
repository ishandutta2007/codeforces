// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt,fla;
long long n,m,t;
int a[maxn],b[maxn];
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); m=read();
		if (n>m){ printf("NO\n"); continue; }
		i=0;
		for (t=1;t<=m+n;t=t*2){
			i++;
			if (((n%(t*2))/t)) a[i]=1; else a[i]=0;
			if (((m%(t*2))/t)) b[i]=1; else b[i]=0;
		}
		k=i; fla=1;
		for (i=1;i<=k;i++){
			a[i]=a[i]+a[i-1];
			b[i]=b[i]+b[i-1];
			if (a[i]<b[i]) fla=0;
		}
		if (fla==1) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}