#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const int maxn=50;
int T,opt;
int n,ans;
char a[maxn],b[maxn],i; 
int main(){
	
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); ans=0;
		scanf("%s",a);
		for (i=0;i<n;i++) b[i]=a[i];
		sort(a,a+n);
		for (i=0;i<n;i++) if (a[i]!=b[i]) ans++;
		printf("%d\n",ans);
	}

	return 0;
}