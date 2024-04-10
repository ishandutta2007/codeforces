// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k;
int n,a[maxn],b[maxn],c[maxn],d[maxn],fla;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) b[i]=read();
	if (a[1]!=b[1]){ printf("No"); return 0; }
	if (a[n]!=b[n]){ printf("No"); return 0; }
	for (i=1;i<n;i++) c[i]=a[i+1]-a[i];
	for (i=1;i<n;i++) d[i]=b[i+1]-b[i];
	sort(c+1,c+n); sort(d+1,d+n); fla=1;
	for (i=1;i<n;i++){
		if (c[i]!=d[i]) fla=0;
	}
	if (fla==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}