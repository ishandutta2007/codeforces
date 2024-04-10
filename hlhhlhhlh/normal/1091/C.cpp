// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
long long i,j,k;
long long ans[maxn],r;
long long n;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void work(long long x){
	r++; ans[r]=(n*(n+1)/2)-(((n/x-1)*(n/x))/2)*x; ans[r]=ans[r]/(n/x);
}
int main(){
	n=read();
	for (i=1;i*i<=n;i++){
		if (n%i==0){
			work(i);
			if (n/i!=i) work(n/i);
		}
	}
	sort(ans+1,ans+r+1);
	for (i=1;i<=r;i++){
		if (ans[i]!=ans[i-1]) printf("%I64d ",ans[i]);
	}
	return 0;
}