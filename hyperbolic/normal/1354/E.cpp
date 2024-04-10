#include <stdio.h>
#include <vector>
int control = 0;
std::vector<int> V[5010];
struct str{
	int first;
	int second;
	int ind;
};
std::vector<str> V2;

int check[5010],parent[5010];
std::pair<int,int> func(int k, int color, int start)
{
	if(check[k])
	{
		if((check[k]+color)%2==1) control = 1;
		return std::make_pair(0,0);
	}
	
	if(color%2==1) check[k] = 1;
	else check[k] = 2;
	parent[k] = start;
	
	std::pair<int,int> ans = std::make_pair(1,0);
	
	for(int i=0;i<V[k].size();i++)
	{
		std::pair<int,int> P = func(V[k][i],color+1,start);
		ans.first += P.second, ans.second += P.first;
	}
	return ans;
}

int color[5010];
int check2[5010][5010];
int func2(int s, int t)
{
	if(s>=V2.size())
	{
		if(t==0) return 1;
		else return 2;
	}
	if(check2[s][t]) return check2[s][t];
	
	if(func2(s+1,t-V2[s].first)==1)
	{
		color[V2[s].ind] = 2;
		return check2[s][t] = 1;
	}
	else if(func2(s+1,t-V2[s].second)==1)
	{
		color[V2[s].ind] = 4;
		return check2[s][t] = 1;
	}
	else return check2[s][t] = 2;
}

int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(int i=1;i<=b;i++)
	{
		int f,g;
		scanf("%d%d",&f,&g);
		V[f].push_back(g);
		V[g].push_back(f);
	}
	
	for(int i=1;i<=a;i++)
	{
		if(check[i]) continue;
		std::pair<int,int> P = func(i,1,i);
		V2.push_back({P.first,P.second,i});
	}
	
	if(control==1)
	{
		printf("NO");
		return 0;
	}
	
	if(func2(0,d)==2)
	{
		printf("NO");
		return 0;
	}
	
	
	for(int i=1;i<=a;i++)
	{
		if(check[i]==check[parent[i]]) color[i] = color[parent[i]];
		else color[i] = 6-color[parent[i]];
	}
	
	
	for(int i=1;i<=a;i++)
	{
		if(color[i]==4)
		{
			if(c==0) color[i] = 3;
			else color[i] = 1, c--;
		}
	}
	
	printf("YES\n");
	for(int i=1;i<=a;i++) printf("%d",color[i]);
}