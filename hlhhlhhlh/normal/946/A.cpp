#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int tot,i,j,k,n,a[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot;
}
int main(){
	n=read();
	for (i=1;i<=n;i++){
		a[i]=read();
		tot=tot+a[i];
	}
	printf("%d\n",tot);
	return 0;
}