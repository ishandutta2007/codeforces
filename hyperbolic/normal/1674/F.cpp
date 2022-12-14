#include <stdio.h>
#include <vector>

char x[1010][1010];
std::vector< std::pair<int,int> > V;
int check[1010][1010];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) V.push_back(std::make_pair(i,j));
	int p = 0, ans = 0;
	
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='*') check[V[p].first][V[p].second] = 1, p++;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='*'&&check[i][j]==0) ans++;
	
	while(c--)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		if(x[d][e]=='.')
		{
			check[V[p].first][V[p].second] = 1;
			if(x[V[p].first][V[p].second]=='*') ans--;
			p++;
			if(check[d][e]==0) ans++;
			x[d][e] = '*';
		}
		else
		{
			p--;
			check[V[p].first][V[p].second] = 0;
			if(x[V[p].first][V[p].second]=='*') ans++;
			if(check[d][e]==0) ans--;
			x[d][e] = '.';
		}
		printf("%d\n",ans);
	}
	
}