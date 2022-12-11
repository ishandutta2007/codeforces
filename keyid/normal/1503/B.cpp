#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

typedef long long LL;

const int MAXN=200005;

int n;
char s[MAXN],a[2][MAXN];

void get_next(int &x,int &y,int b)
{
	if (y+2<n)
		y+=2;
	else
	{
		x++;
		y=(x&1)^b;
	}
}

void solve()
{
	scanf("%d",&n);
	int x1=0,y1=0,x2=0,y2=1;
	for (int i=0;i<n*n;i++)
	{
		int a;
		scanf("%d",&a);
		if (x1<n&&a!=1)
		{
			printf("1 %d %d\n",x1+1,y1+1);
			get_next(x1,y1,0);
		}
		else if (x2<n&&a!=2)
		{
			printf("2 %d %d\n",x2+1,y2+1);
			get_next(x2,y2,1);
		}
		else
		{
			if (x1==n)
			{
				printf("%d %d %d\n",a!=2?2:3,x2+1,y2+1);
				get_next(x2,y2,1);
			}
			else
			{
				printf("%d %d %d\n",a!=1?1:3,x1+1,y1+1);
				get_next(x1,y1,0);
			}
		}
		fflush(stdout);
	}
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	solve();
	return 0;
}