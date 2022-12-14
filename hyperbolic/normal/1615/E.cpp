#include <stdio.h>
#include <vector>
#include <set>

std::vector<int> V[200010];
int prev[200010],len[200010],last[200010],heavy[200010];

int init(int k, int p)
{
	prev[k] = p;
	len[k] = 0;
	last[k] = k;
	heavy[k] = -1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		int t = init(V[k][i],k);
		if(heavy[k]==-1) heavy[k] = V[k][i];
		else if(len[heavy[k]] < len[V[k][i]]) heavy[k] = V[k][i];
	}
	if(heavy[k]!=-1) len[k] = len[heavy[k]]+1, last[k] = last[heavy[k]];
	return len[k];
}

int B = 0;
int check[200010];
int func(int k, int p)
{
	int ans = 1;
	if(check[k]==1) ans = -1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		int t = func(V[k][i],k);
		if(t==-1) ans = -1;
	}
	if(ans!=-1) B++;
	return ans;
}

std::set< std::pair<int,int> > S;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	int C = 0;
	for(int i=2;i<=a;i++) if(V[i].size()==1) C++;
	if(C<=b)
	{
		long long int ans = 0;
		for(int i=C;i<=b;i++)
		{
			long long int t = (long long int)i*(a-i);
			ans = ans>t?ans:t;
		}
		printf("%lld",ans);
		return 0;
	}
	
	init(1,0);
	S.insert(std::make_pair(len[1],1));
	
	for(int i=1;i<=b;i++)
	{
		std::set< std::pair<int,int> > ::iterator it = S.end();
		it--;
		
		int s = (it->second);
		int t = last[s];
		check[t] = 1;
		S.erase(it);
		
		while(1)
		{
			for(int j=0;j<V[t].size();j++)
			{
				if(V[t][j]==heavy[t]) continue;
				if(V[t][j]==prev[t]) continue;
				S.insert(std::make_pair(len[V[t][j]],V[t][j]));
			}
			if(t==s) break;
			t = prev[t];
		}
	}
	
	func(1,0);
	
	long long int ans = (long long int)(a-B-b)*(b-B);
	for(int i=0;i<=B;i++)
	{
		long long int t = (long long int)(a-i-b)*(b-i);
		ans = ans<t?ans:t;
	}
	printf("%lld",ans);
}