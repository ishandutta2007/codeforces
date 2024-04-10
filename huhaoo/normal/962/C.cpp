#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int t=1,r=0,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
int n;
int main()
{
	n=read();
	fd(i,sqrt(n),1)
	{
		int j=i*i,k=n;
		while(k)
		{
			if(k%10==j%10)j/=10;
			k/=10;
		}
		if(!j)
		{
			int j=i*i,k=n,ans=0;
			while(k)
			{
				k/=10;
				ans++;
			}
			while(j)
			{
				j/=10;
				ans--;
			}
			printf("%d\n",ans);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}