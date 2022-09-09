#include<cstdio>

using namespace std;

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0,m=0;scanf("%d%d",&n,&m);m++;
		int ans=0;
		for(int i=30;i>=0;i--)
		{
			if((m&(1<<i))&&!(n&(1<<i)))ans|=1<<i;
			else if((n&(1<<i))&&!(m&(1<<i)))break;
		}
		printf("%d\n",ans);
	}
}