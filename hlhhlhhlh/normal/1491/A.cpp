// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,m,a[maxn],tot=0;
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) tot=tot+a[i];
	for (i=1;i<=m;i++){
		j=read(); k=read();
		if (j==2){
			if (tot>=k) printf("1\n");
			else printf("0\n");
		}
		if (j==1){
			tot=tot-a[k];
			a[k]=1-a[k];
			tot=tot+a[k];
		}
	}
	return 0;
}