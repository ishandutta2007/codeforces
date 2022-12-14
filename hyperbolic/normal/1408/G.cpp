#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 998244353

struct str{
	int value;
	int first;
	int second;
};
std::vector<str> V;
bool cmp(str a, str b)
{
	return a.value<b.value;
}
std::vector<long long int> poly[1510];
int next[1510];
int numV[1510],numE[1510];
int x[1510][1510];

int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) V.push_back({x[i][j],i,j});
	std::sort(V.begin(),V.end(),cmp);
	
	for(int i=1;i<=a;i++) next[i] = i;
	for(int i=1;i<=a;i++) numV[i] = 1;
	for(int i=1;i<=a;i++) numE[i] = 0;
	
	for(int i=1;i<=a;i++) poly[i].push_back(0);
	for(int i=1;i<=a;i++) poly[i].push_back(1);
	
	for(int i=0;i<V.size();i++)
	{
		int s = V[i].first;
		int t = V[i].second;
		s = find(s);
		t = find(t);
		
		if(s==t)
		{
			numE[t]++;
			if(2*numE[t]==numV[t]*(numV[t]-1)) poly[t][1]++;
			continue;
		}
		
		std::vector<long long int> temp;
		for(int j=0;j<poly[s].size()+poly[t].size()-1;j++) temp.push_back(0);
		for(int j=1;j<poly[s].size();j++)
		{
			for(int k=1;k<poly[t].size();k++)
			{
				temp[j+k] += poly[s][j]*poly[t][k];
				temp[j+k] %= MOD;
			}
		}
		
		next[s] = t;
		numV[t] += numV[s];
		numE[t] += numE[s];
		numE[t]++;
		poly[t] = temp;
		if(2*numE[t]==numV[t]*(numV[t]-1)) poly[t][1]++;
	}
	
	int k = find(1);
	for(int i=1;i<=a;i++) printf("%lld ",poly[k][i]);
}