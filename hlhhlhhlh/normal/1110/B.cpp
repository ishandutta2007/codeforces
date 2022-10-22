// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,m,k;
int a[maxn],b[maxn];
long long ans;
int main(){
	n=read(); m=read(); k=read();
	for (i=1;i<=n;i++) a[i]=read();
	ans=n;
	for (i=1;i<n;i++) b[i]=a[i+1]-a[i]-1;
	sort(b+1,b+n);
	j=1; for (i=k;i<n;i++){ ans=ans+b[j]; j++; }
	printf("%I64d\n",ans);
	return 0;
}