// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k;
int n;
int a[maxn];
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
	while ((c<'a')||(c>'z')) c=getchar();
	for (i=1;i<=n;i++){
		a[i]=c-'a';
		c=getchar();
	}
	for (i=2;i<=n;i++){
		if (a[i]<a[i-1]){
			for (j=1;j<=i-2;j++) printf("%c",a[j]+'a');
			for (j=i;j<=n;j++) printf("%c",a[j]+'a');
			return 0;
		}
	}
	for (i=1;i<=n-1;i++) printf("%c",a[i]+'a');
	return 0;
}