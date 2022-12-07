#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 30
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,ans;ll m;
char s[N];
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%s",s+1),n=strlen(s+1),ans=n,m=0;
		for(int i=1;i<=n;i++) s[i]-=48,m=m*10+s[i];
		if(m%25==0) {puts("0");continue;}
		for(int i=2;i<=n;i++)
		{
			if((s[i-1]*10+s[i])%25==0) ans=min(ans,n-i);
			for(int j=1;j<i;j++)
				if((s[j]*10+s[i])%25==0) ans=min(ans,n-i+i-j-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}