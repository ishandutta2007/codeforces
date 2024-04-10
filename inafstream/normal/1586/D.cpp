#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,i,j,pre[105],suf[105],ans[105];

int main()
{
	cin>>n;
	
	rep(i,n)
	{
		putchar('?');
		rep(j,n) printf(" %d",(i==j)+1);
		puts("");fflush(stdout);
		
		int s;cin>>s;
		if(s!=i) suf[pre[i]=s]=i;
	}
	
	rep(i,n)
	{
		putchar('?');
		rep(j,n) printf(" %d",2-(i==j));
		puts("");fflush(stdout);
		
		int s;cin>>s;
		if(s!=i&&s!=0) pre[suf[i]=s]=i;
	}
	
	j=0;
	rep(i,n)
	{
		j=suf[j];
		ans[j]=n-i+1;
	}
	
	putchar('!');
	rep(i,n)
	{
		printf(" %d",ans[i]);
	}
	puts("");fflush(stdout);
	return 0;
}