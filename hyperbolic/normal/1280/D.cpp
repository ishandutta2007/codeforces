#include <stdio.h>
#include <vector>
std::vector<int> V[3010];
std::vector< std::pair<int,long long int> > temp;
std::vector< std::pair<int,long long int> > ans[3010];

int size[3010];
int getSize(int k ,int prev)
{
	if(size[k]) return size[k];
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans += getSize(V[k][i],k);
	}
	return size[k] = ans;
}

long long int x[3010];
void func(int k, int prev)
{
	for(int j=0;j<getSize(k,prev);j++) ans[k].push_back(std::make_pair(-12345,0));
	ans[k][0] = std::make_pair(0,x[k]);
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k);
		
		temp.clear();
		for(int j=0;j<getSize(k,prev);j++) temp.push_back(std::make_pair(-12345,0));
		
		for(int j=0;j<getSize(k,prev)-getSize(V[k][i],k);j++)
		{
			for(int l=0;l<getSize(V[k][i],k);l++)
			{
				std::pair<int,long long int> P;
				if(ans[V[k][i]][l].second>0) P = std::make_pair(ans[k][j].first+ans[V[k][i]][l].first+1,ans[k][j].second);
				else P = std::make_pair(ans[k][j].first+ans[V[k][i]][l].first,ans[k][j].second);
				temp[j+l+1] = temp[j+l+1]>P?temp[j+l+1]:P;
				
				P = std::make_pair(ans[k][j].first+ans[V[k][i]][l].first,ans[k][j].second+ans[V[k][i]][l].second);
				temp[j+l] = temp[j+l]>P?temp[j+l]:P;
			}
		}
		for(int j=0;j<getSize(k,prev);j++) ans[k][j] = temp[j];
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		for(int i=1;i<=a;i++) ans[i].clear();
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) size[i] = 0, x[i] = 0;
		
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			x[i] -= c;
		}
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			x[i] += c;
		}
		
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		
		func(1,0);
		printf("%d\n",ans[1][b-1].first+(ans[1][b-1].second>0?1:0));
	}
}