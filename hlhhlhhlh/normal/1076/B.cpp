// user:halahen
#include<bits/stdc++.h>
using namespace std;
long long n;
long long i,j,k;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	if (n%2==0){
		printf("%I64d\n",n/2);
	}
	else{
		j=0;
		for (i=2;i*i<=n;i++){
			if (n%i==0){
				n=n-i; j=1; break;
			}
		}
		if (j==0) n=0;
		printf("%I64d\n",(n/2)+1);
	}
	return 0;
}