#include <stdio.h>
#include <queue>
#include <vector>

struct str{
	long long int diff;
	long long int value;
	int size;
};
bool operator<(str a, str b)
{
	if(a.diff==b.diff) return a.value<b.value;
	return a.diff<b.diff;
}
std::priority_queue<str> Q[3];
long long int ans = 0;

struct str2{
	int first;
	long long int second;
	int cost;
};

std::vector<str2> V[200010];
int func(int k, int parent)
{
	int size = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==parent) continue;
		size += func(V[k][i].first,k);
	}
	if(size==0) size++;
		
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==parent)
		{
			ans += (long long int)V[k][i].second * size;
			long long int t = V[k][i].second - (V[k][i].second/2);
			Q[V[k][i].cost].push({t*size,V[k][i].second,size});
		}
	}
	return size;
}

long long int check1[6000010],check2[6000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		while(!Q[1].empty()) Q[1].pop();
		while(!Q[2].empty()) Q[2].pop();
		
		int a;
		long long int b;
		scanf("%d%lld",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int c,d,e,f;
			scanf("%d%d%d%d",&c,&d,&e,&f);
			V[c].push_back({d,e,f});
			V[d].push_back({c,e,f});
		}
		
		func(1,0);
		if(ans<=b)
		{
			printf("0\n");
			continue;
		}
		
		long long int s1 = 0, s2 = 0;
		int c1 = 1, c2 = 1;
		while(!Q[1].empty())
		{
			str A = Q[1].top();
			Q[1].pop();
			//printf("%lld %lld %d??\n",A.diff,A.value,A.size);
			
			if(A.diff==0) break;
			s1 += A.diff;
			check1[c1] = s1;
			long long int s = A.value/2;
			long long int t = s - (s/2);
			Q[1].push({t*A.size,s,A.size});
			c1++;
		}
		
		while(!Q[2].empty())
		{
			str A = Q[2].top();
			Q[2].pop();
			if(A.diff==0) break;
			s2 += A.diff;
			check2[c2] = s2;
			long long int s = A.value/2;
			long long int t = s - (s/2);
			Q[2].push({t*A.size,s,A.size});
			c2++;
		}
		
		int min = 1, max = 6000000;
		int ans2 = max;
		while(min<=max)
		{
			int h = (min+max)/2;
			for(int j=0;j<c2;j++)
			{
				if(2*j<=h)
				{
					long long int t = check2[j];
					if(c1<=h-2*j) t += check1[c1-1];
					else t += check1[h-2*j];
					
					if(ans-t<=b)
					{
						ans2 = h;
						max = h-1;
						goto u;
					}
				}
			}
			min = h+1;
			u:;
		}
		printf("%d\n",ans2);
	}
}