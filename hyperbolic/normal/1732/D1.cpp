#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

struct segTree{
	int value[24000010];
	void setValue(int ind, int val, int l=0, int r=6000000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L, int R,int l=0, int r=6000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

std::pair<long long int, long long int> query[200010];
std::set<long long int> S;
std::vector<long long int> index,V;
std::map<long long int, long long int> hash, hash2;
std::vector<long long int> save[200010];

long long int start[200010],size[200010];
char x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		long long int b;
		scanf("%lld",&b);
		if(x[1]=='+') query[i] = std::make_pair(1,b);
		if(x[1]=='-') query[i] = std::make_pair(2,b);
		if(x[1]=='?') query[i] = std::make_pair(3,b);
	}
	
	for(int i=1;i<=a;i++) if(query[i].first==1) S.insert(query[i].second);
	for(int i=1;i<=a;i++) if(query[i].first==3) index.push_back(query[i].second);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++)
	{
		long long int val = index[i];
		for(int j=1;;j++)
		{
			if(S.find(j*val)==S.end()) break;
			else
			{
				V.push_back(j*val);
				size[i]++;
			}
		}
	}
	
	std::sort(V.begin(),V.end());
	V.erase(std::unique(V.begin(),V.end()),V.end());
	for(int i=0;i<V.size();i++) hash2[V[i]] = i;
	
	for(int i=0;i<index.size();i++)
	{
		long long int val = index[i];
		for(int j=1;j<=size[i];j++) save[hash2[j*val]].push_back(i);
	}
	
	for(int i=0;i<index.size();i++) hash[index[i]] = i;
	for(int i=1;i<=a;i++)
	{
		if(query[i].first==3) query[i].second = hash[query[i].second];
		else
		{
			if(hash2.find(query[i].second)==hash2.end()) query[i].second = -1;
			else query[i].second = hash2[query[i].second];
		}
	}
	
	start[0] = 0;
	for(int i=1;i<index.size();i++) start[i] = start[i-1] + size[i-1];
	
	for(int i=1;i<=a;i++)
	{
		int val = query[i].second;
		if(val==-1) continue;
		if(query[i].first==1)
		{
			int t = val;
			for(int j=0;j<save[t].size();j++)
			{
				int s = save[t][j];
				long long int gap = V[val]/index[s] - 1;
				T.setValue(start[s]+gap,1);
			}
		}
		else if(query[i].first==2)
		{
			int t = val;
			for(int j=0;j<save[t].size();j++)
			{
				int s = save[t][j];
				long long int gap = V[val]/index[s] - 1;
				T.setValue(start[s]+gap,0);
			}
		}
		else
		{
			int min = start[val];
			int max = start[val] + size[val]-1;
			int ans = start[val] + size[val];
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T.getSum(start[val],h)==h-start[val]+1) min = h+1;
				else
				{
					ans = h;
					max = h-1;
				}
			}
			printf("%lld\n",(ans-start[val]+1)*index[val]);
		}
	}
}