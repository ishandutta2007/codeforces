// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
long long n,m,ans;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	if (m%n!=0) ans++;
	ans=ans+m/n;
	printf("%I64d\n",ans);
	return 0;
}