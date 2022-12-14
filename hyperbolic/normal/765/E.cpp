#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[200010];
std::vector<int> trash,save;

int func(int k, int prev)
{
	int C = -1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		int t = func(V[k][i],k);
		if(t==-1) return -1;
		if(C==-1) C = t;
		else if(C!=t)
		{
			trash.push_back(k);
			return -1;
		}
	}
	return C+1;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	int root = -1;
	for(int i=1;i<=a;i++) if(V[i].size()>=3) root = i;
	if(root==-1)
	{
		int ans = a-1;
		while(ans%2==0) ans/=2;
		printf("%d",ans);
		return 0;
	}
	
	for(int i=0;i<V[root].size();i++)
	{
		int t = func(V[root][i],root);
		if(t!=-1) save.push_back(t+1);
	}
	std::sort(save.begin(),save.end());
	save.erase(std::unique(save.begin(),save.end()),save.end());
	
	if(save.size()==1)
	{
		if(trash.size()==0)
		{
			int ans = save[0];
			while(ans%2==0) ans/=2;
			printf("%d",ans);
			return 0;
		}
		else if(trash.size()==1) root = trash[0];
		else
		{
			printf("-1");
			return 0;
		}
	}
	else if(save.size()==2)
	{
		if(trash.size()==0)
		{
			int ans = save[0] + save[1];
			while(ans%2==0) ans/=2;
			printf("%d",ans);
			return 0;
		}
		else
		{
			printf("-1");
			return 0;
		}
	}
	else
	{
		printf("-1");
		return 0;
	}
	
	save.clear();
	trash.clear();
	
	for(int i=0;i<V[root].size();i++)
	{
		int t = func(V[root][i],root);
		if(t!=-1) save.push_back(t+1);
	}
	std::sort(save.begin(),save.end());
	save.erase(std::unique(save.begin(),save.end()),save.end());
	
	if(save.size()==1)
	{
		if(trash.size()==0)
		{
			int ans = save[0];
			while(ans%2==0) ans/=2;
			printf("%d",ans);
			return 0;
		}
		else
		{
			printf("-1");
			return 0;
		}
	}
	else if(save.size()==2)
	{
		if(trash.size()==0)
		{
			int ans = save[0] + save[1];
			while(ans%2==0) ans/=2;
			printf("%d",ans);
			return 0;
		}
		else
		{
			printf("-1");
			return 0;
		}
	}
	else
	{
		printf("-1");
		return 0;
	}
	
}