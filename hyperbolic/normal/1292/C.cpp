#include <stdio.h>
#include <vector>

std::vector<int> V[3010];
int check1[3010][3010];
long long int check2[3010][3010];
int size(int k, int prev)
{
	if(check1[k][prev]) return check1[k][prev];
	int sum = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		sum += size(V[k][i],k);
	}
	return check1[k][prev] = sum;
}

long long int func(int s, int t, int sPrev, int tPrev)
{
	if(check2[s][t]!=-1) return check2[s][t];
	
	long long int c1 = size(s,sPrev);
	long long int c2 = size(t,tPrev);
	
	long long int ans = 0;
	for(int i=0;i<V[s].size();i++)
	{
		if(V[s][i]==sPrev) continue;
		long long int S = func(V[s][i],t,s,tPrev);
		ans = ans>S?ans:S;
	}
	for(int i=0;i<V[t].size();i++)
	{
		if(V[t][i]==tPrev) continue;
		long long int S = func(s,V[t][i],sPrev,t);
		ans = ans>S?ans:S;
	}
	return check2[s][t] = ans + c1*c2;
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
	
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) check2[i][j] = -1;
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			long long int S = func(i,V[i][j],V[i][j],i);
			ans = ans>S?ans:S;
		}
	}
	printf("%lld",ans);
}