#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
long long n,m,fla;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read(); fla=0;
	while ((n!=0)&&(m!=0)){
		fla=0;
		if (n>=2*m){
			n=n%(2*m); fla=1;
		}
		else{
			if (m>=2*n){
				m=m%(2*n); fla=1;
			}
		}
		if (fla==0) break;
	}
	printf("%I64d %I64d\n",n,m);
	return 0;
}