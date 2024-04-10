// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int n;
long long ans;
int a[maxn],b[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	for (i=1;i<=n;i++){
		a[i]=read(); b[i]=read();
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	ans=n;
	for (i=1;i<=n;i++){
		ans=ans+max(a[i],b[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}