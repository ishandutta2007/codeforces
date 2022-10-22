// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt,n,u,v;
int a[maxn],fla;
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); u=read(); v=read();
		for (i=1;i<=n;i++) a[i]=read();
		fla=1;
		for (i=1;i<n;i++) if (a[i]!=a[i+1]) fla=0;
		if (fla==1){
			printf("%d\n",v+min(u,v));
			continue;
		}
		fla=1;
		for (i=1;i<n;i++) if (abs(a[i]-a[i+1])>1) fla=0;
		if (fla==1){
			printf("%d\n",min(u,v));
			continue;
		}
		printf("0\n");
	}
	return 0;
}