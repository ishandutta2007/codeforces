#include <stdio.h>
#include <algorithm>

struct str{
	int value;
	int first;
	int second;
}x[1000010];
bool cmp(str a, str b)
{
	return a.value<b.value;
}

int y[510][510],z[510][510];
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=d;i++)
	{
		int e,f,g;
		scanf("%d%d%d",&e,&f,&g);
		x[i]={g,e,f};
	}
	std::sort(x+1,x+d+1,cmp);
	
	int min = 1, max = d;
	int ans = -1;
	while(min<=max)
	{
		int h = (min+max)/2;
		for(int i=min;i<=h;i++) y[x[i].first][x[i].second] = 1;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) z[i][j] = z[i][j-1] + y[i][j];
		for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) z[i][j] += z[i-1][j];
		
		for(int i=1;i+c-1<=a;i++)
		{
			for(int j=1;j+c-1<=b;j++)
			{
				int t = z[i+c-1][j+c-1] - z[i-1][j+c-1] - z[i+c-1][j-1] + z[i-1][j-1];
				if(t==c*c) goto u;
			}
		}
		
		min = h+1;
		continue;
		
		u:;
		ans = x[h].value;
		for(int i=min;i<=h;i++) y[x[i].first][x[i].second] = 0;
		max = h-1;
	}
	printf("%d",ans);
}