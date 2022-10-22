#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const int maxn=8000010;
int T=1,opt;
long long n,p;
long long f[maxn],g[maxn];
int main(){

	for (opt=1;opt<=T;opt++){
		n=read(); p=read();
		for (int i=n;i>=0;i--) f[i]=0;
		for (int i=n;i>=0;i--) g[i]=0;
		f[n]=1; g[n]=1;
		for (int i=n-1;i>=1;i--){
			f[i]=g[i+1];
			for (int j=2;j*i<=n;j++){
				f[i]=(f[i]-g[i*j+j]+g[i*j]+p)%p;
			}
			g[i]=(g[i+1]+f[i])%p;
		}
		printf("%lld\n",f[1]);
	}

	return 0;
}