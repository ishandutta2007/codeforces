#include<cstdio>
#include<algorithm>

using namespace std;

int calc(int x,int pos)
{
	int ans=0;
	for(int i=20;i>pos;i--)if(x&(1<<i))ans+=1<<(i-1),x-=1<<i;
	if(x&(1<<pos))ans+=x-(1<<pos)+1;return ans;
}

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int l=0,r=0;scanf("%d%d",&l,&r);
		int ans=r-l+1;for(int i=0;i<=20;i++)ans=min(ans,r-l+1-(calc(r,i)-calc(l-1,i)));
		printf("%d\n",ans);
	}
}