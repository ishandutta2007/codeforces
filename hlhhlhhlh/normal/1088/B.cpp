// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int n,m,a[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++){
		if (a[i]!=a[i-1]){
			printf("%d\n",a[i]-a[i-1]);
			m--;
			if (m==0) return 0;
		}
	}
	for (i=1;i<=m;i++) printf("0\n");
	return 0;
}