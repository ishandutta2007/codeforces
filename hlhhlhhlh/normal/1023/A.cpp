// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k;
int n,m,thi;
char a[maxn],b[maxn],c;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	c=' '; while (((c<'a')||(c>'z'))&&(c!='*')) c=getchar(); 
	for (i=1;i<=n;i++){
		a[i]=c; c=getchar();
		if (a[i]=='*') thi=i;
	}
	while (((c<'a')||(c>'z'))&&(c!='*')) c=getchar(); 
	for (i=1;i<=m;i++){
		b[i]=c; c=getchar();
	}
	if (thi==0){
		if (n!=m) printf("NO\n");
		else{
			for (i=1;i<=n;i++){
				if (a[i]!=b[i]){
					printf("NO\n"); return 0;
				}
			}
			printf("YES\n");
		}
		return 0;
	}
	if (n-1>m){
		printf("NO\n"); return 0;
	}
	for (i=1;i<=thi-1;i++){
		if (a[i]!=b[i]){
			printf("NO\n"); return 0;
		}
	}
	for (i=n,j=m;i>=thi+1;i--,j--){
		if (a[i]!=b[j]){
			printf("NO\n"); return 0;
		}
	}
	printf("YES\n");
	return 0;
}