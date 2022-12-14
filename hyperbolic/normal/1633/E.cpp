#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 200000002

long long int abs(long long int k)
{
	return k>0?k:-k;
}

struct str{
	long long int first;
	long long int second;
	long long int value;
	long long int index;
}edge[300010],edge2[300010];
bool operator<(str A, str B)
{
	return A.value<B.value;
}

std::vector<long long int> event;

long long int next[1010];
long long int check[1010];
long long int find(long long int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

std::pair<long long int, long long int> value[300010];
long long int func(long long int t)
{
	t*=2;
	long long int ans = event.size()-1;
	long long int min = 0, max = event.size()-1;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		if(event[h]>=t)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
	}
	
	return (value[ans].first + t*value[ans].second)/2;
}

long long int query[300010];
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	for(long long int i=1;i<=b;i++)
	{
		long long int c,d,e;
		scanf("%lld%lld%lld",&c,&d,&e);
		edge[i] = {c,d,2*e,i};
	}
	
	for(long long int i=1;i<=b;i++)
	{
		event.push_back(edge[i].value-1);
		event.push_back(edge[i].value);
		event.push_back(edge[i].value+1);
	}
	
	for(long long int i=1;i<=b;i++)
	{
		for(long long int j=i+1;j<=b;j++)
		{
			long long int val = (edge[i].value+edge[j].value)/2;
			event.push_back(val-1);
			event.push_back(val);
			event.push_back(val+1);
		}
	}
	
	std::sort(event.begin(),event.end());
	event.push_back(MAX);
	
	for(long long int i=0;i<event.size();i++)
	{
		for(long long int j=1;j<=b;j++)
		{
			edge2[j] = edge[j];
			edge2[j].value = abs(edge[j].value-event[i]);
		}
		std::sort(edge2+1,edge2+b+1);
		
		for(long long int j=1;j<=a;j++) next[j] = j;
		for(long long int j=1;j<=b;j++) check[j] = 0;
		for(long long int j=1;j<=b;j++)
		{
			long long int s = edge2[j].first;
			long long int t = edge2[j].second;
			s = find(s);
			t = find(t);
			if(s!=t)
			{
				check[edge2[j].index] = 1;
				next[s] = t;
			}
		}
		
		long long int s1 = 0, s2 = 0;
		for(long long int j=1;j<=b;j++)
		{
			if(check[j]==1)
			{
				if(edge[j].value>=event[i])
				{
					s1+= edge[j].value;
					s2--;
				}
				else
				{
					s1-= edge[j].value;
					s2++;
				}
			}
		}
		
		value[i] = std::make_pair(s1,s2);
	}
	
	long long int c,d,e,f,g;
	scanf("%lld%lld%lld%lld%lld",&c,&d,&e,&f,&g);
	for(long long int i=1;i<=c;i++) scanf("%lld",&query[i]);
	
	long long int ans = 0;
	for(long long int i=1;i<=c;i++)
	{
		ans ^= func(query[i]);
	}
	
	long long int last = query[c];
	for(long long int i=c+1;i<=d;i++)
	{
		last = (last*e+f)%g;
		ans ^= func(last);
	}
	printf("%lld",ans);
}