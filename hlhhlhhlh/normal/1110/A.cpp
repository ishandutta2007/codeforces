// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int n,m;
long long ans;
int a[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	for (i=1;i<=m;i++) a[i]=read();
	n=n%2;
	for (i=1;i<m;i++){
		ans=(ans+n*a[i])%2;
	}
	ans=(ans+a[m])%2;
	if (ans==1) printf("odd\n");
	else printf("even\n");
	return 0;
}