#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,q,s;
int i,j;
int a[2][100005];

int main()
{
	scanf("%d%d",&n,&q);
	
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		if (a[x][y])
		{
			s-=a[x^1][y-1];
			s-=a[x^1][y];
			s-=a[x^1][y+1];
			a[x][y]^=1;
		}
		else
		{
			s+=a[x^1][y-1];
			s+=a[x^1][y];
			s+=a[x^1][y+1];
			a[x][y]^=1;
		}
		
		if (s)
		{
			puts("No");
		}
		else
		{
			puts("Yes");
		}
	}
	
	return 0;
}