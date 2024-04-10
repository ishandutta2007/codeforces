// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int mx,l,r;
int b[maxn],c[maxn],d[maxn],tot,a[maxn];
int main(){
	
	l=read(); r=read();
	for (i=30;i>=10;i--){
		tot++; b[tot]=i; c[tot]=31; d[tot]=1;
		k=1;
		for (j=30;j>=i+1;j--){
			tot++; b[tot]=i; c[tot]=j; d[tot]=k;
			k=k*2;
		}
	}
	a[30]=1; for (i=29;i>=10;i--) a[i]=a[i+1]*2;
	for (i=10;i<=30;i++){
		if (r-l+1>a[i]){
			tot++; b[tot]=1; c[tot]=i; d[tot]=r-a[i];
			r=r-a[i];
		}
	}
	tot++; b[tot]=1; c[tot]=31; d[tot]=l;
	printf("YES\n");
	printf("31 %d\n",tot);
	for (i=1;i<=tot;i++){
		printf("%d %d %d\n",b[i],c[i],d[i]);
	}
	
	return 0;
}