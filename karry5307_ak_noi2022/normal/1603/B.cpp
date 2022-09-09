#include<cstdio>

using namespace std;

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		long long x=0,y=0;scanf("%lld%lld",&x,&y);
		if(x>y){printf("%lld\n",x+y);continue;}
		if(x==y){printf("%lld\n",x);continue;}
		long long t=y/x;printf("%lld\n",(y+t*x)/2);
	}
}