// user:halahen
#include<bits/stdc++.h>
using namespace std;
const long long maxn=100010;
long long i=2;
long long n,k,t;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); k=read();
	if ((n==1)||(k<=2)){
		printf("0\n"); return 0;
	}
	if (n>=k-1){
		printf("%I64d\n",(k/i)-1+(k%i));
		return 0;
	}
	else{
		t=i*n-k+1;
		if (t>0) printf("%I64d\n",t/i);
		else printf("0\n");
	}
	return 0;
}