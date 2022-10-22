// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int n,a[maxn],m;
char c=' ';
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	while ((c<'0')||(c>'9')){ c=getchar(); }
	for (i=1;i<=n;i++){
		a[i]=c-'0';
		if (a[i]==8) m++;
		c=getchar();
	}
	printf("%d",min(m,n/11));
	return 0;
}