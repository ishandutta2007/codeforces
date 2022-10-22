// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
long long n,m,t,ans;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	if (n<=9){
		printf("%d\n",n); return 0;
	}
	m=9;
	while (m<=n){
		m=m*10+9;
	}
	m=m/10;
	t=n-m;
	while (m!=0){
		ans=ans+m%10; m=m/10;
	}
	while (t!=0){
		ans=ans+t%10; t=t/10; 
	}
	printf("%I64d\n",ans);
	return 0;
}