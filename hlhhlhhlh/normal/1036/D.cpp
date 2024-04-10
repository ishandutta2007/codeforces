// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k;
int n,m,x,y;
long long a[maxn],b[maxn],ans;
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
	m=read();
	for (i=1;i<=m;i++) b[i]=read();
	for (i=1;i<=n;i++) a[i]=a[i]+a[i-1];
	for (i=1;i<=m;i++) b[i]=b[i]+b[i-1];
	if (a[n]!=b[m]){
		printf("-1\n"); return 0;
	}
	x=1; y=1;
	for (i=1;i<=n+m-2;i++){
		if (a[x]==b[y]) ans++;
		if (a[x]<b[y]) x++; else y++;
	}
	ans++;
	printf("%d\n",ans);
	return 0;
}