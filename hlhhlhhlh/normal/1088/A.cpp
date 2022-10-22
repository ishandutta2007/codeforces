// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int i,j,k;
int n,r,a[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	if (n==1){
		printf("-1\n");
	}
	else{
		printf("%d %d\n",n,n);
	}
	/*
	for (i=2;i*i<=n;i++){
		while (n%i==0){
			n=n/i;
			r++; a[r]=i;
		}
	}
	if (n!=1){
		r++; a[r]=n;
	}
	*/
	return 0;
}