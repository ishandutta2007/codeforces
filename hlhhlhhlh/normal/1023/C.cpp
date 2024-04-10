// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int i,j,k;
int n,m,t;
int f[maxn],r,ha[maxn],g[maxn];
char a[maxn],c=' ';
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read(); t=(n-m)/2;
	c=' '; while ((c!='(')&&(c!=')')) c=getchar(); 
	for (i=1;i<=n;i++){
		a[i]=c; c=getchar();
	}
	for (i=1;i<=n;i++){
		if (a[i]=='('){
			r++; f[r]=i;
		}
		else{
			ha[f[r]]=i; ha[i]=f[r]; f[r]=0; r--;
		}
	}
	for (i=1;i<=n;i++){
		if (t==0) break;
		if (a[i]=='('){
			t--;
			g[i]=1; g[ha[i]]=1;
			if (t==0) break;
		}
	}
	for (i=1;i<=n;i++){
		if (g[i]==0) printf("%c",a[i]);
	}
	return 0;
}