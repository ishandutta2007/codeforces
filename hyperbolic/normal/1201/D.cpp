#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
 
std::vector<int> V[200010];
int prev[200010],next[200010];
int x[200010],last[200010],d;
long long int MAX = 1;
 
std::map<int,long long int> check[200010];
long long int dist(long long int s, long long int t)
{
	return s>t? s-t:t-s;
}
long long int func(int s, int t)
{
	if(V[s].size()==0) return func(s+1,t)+1;
	int start = V[s][0], end = V[s][V[s].size()-1];
	if(last[s]==1)
	{
		long long int s1 = dist(t,end) + dist(end,start);
		long long int s2 = dist(t,start) + dist(end,start);
		return s1<s2?s1:s2;
	}
	
	if(check[s][t]) return check[s][t];
	
	int p1=0,p2=0;
	int min = 1, max = d;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(x[h]<=start)
		{
			p1 = h;
			min = h+1;
		}
		else max = h-1;
	}
	min = 1, max = d;
	
	while(min<=max)
	{
		int h = (min+max)/2;
		if(x[h]<=end)
		{
			p2 = h;
			min = h+1;
		}
		else max = h-1;
	}
	long long int s1 = MAX,s2 = MAX,s3 = MAX ,s4 = MAX;
	if(1<=p1 && p1<=d && x[p1]<=start) s1 = dist(t,end) + dist(end,start) + dist(x[p1],start)+1 + func(s+1,x[p1]);
	if(1<=p1+1 && p1+1<=d && x[p1+1]>=start) s2 = dist(t,end) + dist(end,start) + dist(x[p1+1],start)+1 + func(s+1,x[p1+1]);
	if(1<=p2 && p2<=d && x[p2]<=end) s3 = dist(t,start) + dist(end,start) + dist(x[p2],end)+1 + func(s+1,x[p2]);
	if(1<=p2+1 && p2+1<=d && x[p2+1]>=end) s4 = dist(t,start) + dist(end,start) + dist(x[p2+1],end)+1 + func(s+1,x[p2+1]);
	
	long long int ans = s1;
	ans = ans<s2?ans:s2;
	ans = ans<s3?ans:s3;
	ans = ans<s4?ans:s4;
	return check[s][t] = ans;
}
int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	int a,b,c;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=c;i++)
	{
		int e,f;
		scanf("%d%d",&e,&f);
		V[e].push_back(f);
	}
	for(int i=1;i<=a;i++) std::sort(V[i].begin(),V[i].end());
	for(int i=a;i>=1;i--)
	{
		last[i] = 1;
		if(V[i].size()>=1) break;
	}
	for(int i=1;i<=d;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+d+1);
	if(V[1].size()==0) printf("%lld",func(2,x[1]) + dist(1,x[1])+1);
	else printf("%lld",func(1,1));
}