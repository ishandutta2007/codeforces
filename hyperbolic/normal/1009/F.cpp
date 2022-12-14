#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> V[1000010];
int left[1000010],right[1000010],prev[1000010],height[1000010];
int init(int k, int p, int h, int &C)
{
	right[k] = left[k] = C++;
	height[k] = h;
	prev[k] = p;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		right[k] = init(V[k][i],k,h+1,C);
	}
	return right[k];
}

struct str{
	int first;
	int second;
	int index;
};
bool cmp(str a, str b)
{
	if((a.first/1000)==(b.first/1000)) return a.second<b.second;
	return (a.first/1000)<(b.first/1000);
	/*if(a.first==b.first) a.second<b.second;
	return a.first<b.first;*/
}
std::vector<str> query;

struct str2{
	int first;
	int second;
};
bool operator<(str2 a, str2 b)
{
	if(a.second==b.second) return a.first>b.first;
	return a.second<b.second;
}

struct segTree{
	std::pair<int,int> value[4000010];
	
	void addValue(int ind ,int val, int l=1, int r=1000000, int v=1)
	{
		if(l==r) value[v].first = val, value[v].second = ind;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			if(value[2*v].first==value[2*v+1].first) value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
			else value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	std::pair<int,int> getMax(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return std::make_pair(0,0);
		else if(R<l) return std::make_pair(0,0);
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> P1 = getMax(L,R,l,h,2*v);
			std::pair<int,int> P2 = getMax(L,R,h+1,r,2*v+1);
			if(P1.first==P2.first) return P1<P2?P1:P2;
			else return P1>P2?P1:P2;
		}
	}
}T;

std::vector<int> temp;
int temp2[1000010];
int count[1000010];
void insert(int k, int type)
{
	//T.addValue(k,type);
	count[k] += type;
	temp.push_back(k);
	temp2[k] = 1;
}

int ans[1000010];
int x[1000010];
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
	int C = 1;
	init(1,0,1,C);
	
	for(int i=1;i<=a;i++) query.push_back({left[i],right[i],i});
	for(int i=1;i<=a;i++) x[left[i]] = height[i];
	
	std::sort(query.begin(),query.end(),cmp);
	
	int s = 1, t = 1;
	for(int i=1;i<=a;i++) T.addValue(i,0);
	insert(x[1],1);
	
	for(int i=0;i<query.size();i++)
	{
		int L = query[i].first;
		int R = query[i].second;
		while(s<L) insert(x[s],-1), s++;
		while(s>L) s--, insert(x[s],1);
		while(t>R) insert(x[t],-1), t--;
		while(t<R) t++, insert(x[t],1);
		
		for(int j=0;j<temp.size();j++)
		{
			if(temp2[temp[j]]==1)
			{
				temp2[temp[j]] = 0;
				T.addValue(temp[j],count[temp[j]]);
			}
		}
		temp.clear();
		
		//printf("%d %d %d??\n",it->first,it->second,query[i].index);
		ans[query[i].index] = T.getMax(1,a).second;
	}
	
	for(int i=1;i<=a;i++) printf("%d\n",ans[i]-height[i]);
}