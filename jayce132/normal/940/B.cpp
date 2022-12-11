#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

ll ans=0;

int main()
{
	int n=read(),k=read(),A=read(),B=read();
	while(n>=2)
	{
		if(n<k || k==1)
		{
			ans+=(ll)(n-1)*A;
			n=1;
		}else
		if(n%k)
		{
			ans+=(ll)(n%k)*A;
			n-=n%k;
		}else
		{
			int to=n/k;
			if((ll)(n-to)*A<B)ans+=A*(n-to);
			else ans+=B;
			n/=k;
		}
	}
	printf("%lld\n",ans);
	return 0;
}