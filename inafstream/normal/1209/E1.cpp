#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

int t,n,m,a[5][105];
struct node
{
	int x,y,v;
}s[405];

bool cmp(node x,node y)
{
	return x.v>y.v;
}

int main()
{
	int i,j;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		rep(i,n)
		{
			rep(j,m)
			{
				scanf("%d",&a[i][j]);
				s[(i-1)*m+j].x=j;
				s[(i-1)*m+j].y=i;
				s[(i-1)*m+j].v=a[i][j];
			}
		}
		
		sort(s+1,s+n*m+1,cmp);
		if (n<=3)
		{
			int sum=0;
			rep(i,n) sum+=s[i].v;
			printf("%d\n",sum);
			continue;
		}
		else
		{
			for (i=5;i>=1;i--)
			{
				swap(s[i],s[5]);
				int a1,a2,b1,b2;
				if (s[1].x==s[2].x&&s[3].x==s[4].x)
				{
					a1=s[1].y;a2=s[2].y;
					b1=s[3].y;b2=s[4].y;
				}
				else if (s[1].x==s[3].x&&s[2].x==s[4].x)
				{
					a1=s[1].y;a2=s[3].y;
					b1=s[2].y;b2=s[4].y;
				}
				else if (s[1].x==s[4].x&&s[2].x==s[3].x)
				{
					a1=s[1].y;a2=s[4].y;
					b1=s[2].y;b2=s[3].y;
				}
				else
				{
					printf("%d\n",s[1].v+s[2].v+s[3].v+s[4].v);
					break;
				}
				int c1=0,c2=0,d1=0,d2=0;
				if (a1>a2) swap(a1,a2);
				if (b1>b2) swap(b1,b2);
				if (a1+1==a2||(a1==1&&a2==n)) c1=1; else c2=1;
				if (b1+1==b2||(b1==1&&b2==n)) d1=1; else d2=1;
				if ((c1&&d1)||(c2&&d2))
				{
					printf("%d\n",s[1].v+s[2].v+s[3].v+s[4].v);
					break;
				}
				swap(s[i],s[5]);
			}
		}
	}
	return 0;
}