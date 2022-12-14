#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
struct segTree{
	long long int value[10000010];
	void setValue(int ind, long long int val, int l=1, int r=2300000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=1, int r=2300000, int v=1)
	{
		if(L>R) return 0;
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

long long int ans[200010];
std::vector<int> V[200010];
std::vector< std::pair< std::pair<int,int> , int> > save;
std::map< std::pair<int,int> , int > hash;

std::vector< std::pair<int,int> > event[200010];
int main()
{
	for(int i=1;i<=200000;i++) for(int j=i;j<=200000;j+=i) V[j].push_back(i);
	
	for(int i=1;i<=200000;i++)
	{
		int C = 0;
		for(int j=V[i].size()-2;j>=0;j--)
		{
			save.push_back(std::make_pair( std::make_pair(V[i][j],i),C));
			C++;
		}
	}
	
	std::sort(save.begin(),save.end());
	for(int i=0;i<save.size();i++) hash[save[i].first] = i+1;
	
	for(int i=0;i<save.size();i++) T.setValue(i+1,save[i].second);
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		event[c].push_back(std::make_pair(b,i));
	}
	
	for(int i=200000;i>=1;i--)
	{
		for(int j=0;j+1<V[i+1].size();j++)
		{
			std::pair<int,int> P = std::make_pair(V[i+1][j],i+1);
			T.setValue(hash[P],0);
		}
		
		for(int j=0;j<event[i].size();j++)
		{
			int L = event[i][j].first;
			int start = save.size();
			int min = 0, max = save.size()-1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(save[h].first.first<L) min = h+1;
				else
				{
					start = h;
					max = h-1;
				}
			}
			long long int t = i-event[i][j].first + 1;
			ans[event[i][j].second] = (long long int)t*(t-1)*(t-2)/6 - T.getSum(start+1,save.size());
			
			int l = 2*event[i][j].first-1, r = i;
			if(l<=r) ans[event[i][j].second] -= (r/6 - l/6);
			l = (5*event[i][j].first-1)/2+1-1, r = i;
			if(l<=r) ans[event[i][j].second] -= (r/15 - l/15);
		}
	}
	
	for(int i=1;i<=a;i++) printf("%lld\n",ans[i]);
}