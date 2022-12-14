#include <stdio.h>
#include <vector>
#define MAX 12345678

int a;
struct SegTree1{
	int value[3000010];
	int index[3000010],number[3000010];
	void update(int k)
	{
		if(value[2*k]==0&&value[2*k+1]==0)
		{
			index[k] = 0;
			value[k] = 0;
			number[k] = 0;
		}
		else if(value[2*k]==0) index[k] = index[2*k+1], value[k] = value[2*k+1], number[k] = number[2*k+1];
		else if(value[2*k+1]==0) index[k] = index[2*k], value[k] = value[2*k], number[k] = number[2*k];
		else
		{
			if(value[2*k]>=value[2*k+1]) index[k] = index[2*k], value[k] = value[2*k], number[k] = number[2*k];
			else index[k] = index[2*k+1], value[k] = value[2*k+1], number[k] = number[2*k+1];
		}
	}
	void insert(int ind, int val, int num, int l = 1, int r = 2*a, int v = 1)
	{
		if(l==r)
		{
			index[v] = ind;
			value[v] = val;
			number[v] = num;
			return;
		}
		int h = (l+r)/2;
		if(ind<=h) insert(ind,val,num,l,h,2*v);
		else insert(ind,val,num,h+1,r,2*v+1);
		update(v);
	}
	std::pair<int,int> get(int L, int R, int l=1,int r=2*a,int v=1)
	{
		if(L<=l&&r<=R) return std::make_pair(number[v],value[v]);
		else if(R<l) return std::make_pair(0,0);
		else if(r<L) return std::make_pair(0,0);
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> p1 = get(L,R,l,h,2*v);
			std::pair<int,int> p2 = get(L,R,h+1,r,2*v+1);
			if(p1.second>=p2.second) return p1;
			else return p2;
		}
	}
}T1;

struct SegTree2{
	int value[3000010];
	int index[3000010],number[3000010];
	void update(int k)
	{
		if(value[2*k]==MAX&&value[2*k+1]==MAX)
		{
			index[k] = 0;
			value[k] = MAX;
			number[k] = 0;
		}
		else if(value[2*k]==MAX) index[k] = index[2*k+1], value[k] = value[2*k+1], number[k] = number[2*k+1];
		else if(value[2*k+1]==MAX) index[k] = index[2*k], value[k] = value[2*k], number[k] = number[2*k];
		else
		{
			if(value[2*k]<=value[2*k+1]) index[k] = index[2*k], value[k] = value[2*k], number[k] = number[2*k];
			else index[k] = index[2*k+1], value[k] = value[2*k+1], number[k] = number[2*k+1];
		}
	}
	void insert(int ind, int val, int num, int l = 1, int r = 2*a, int v = 1)
	{
		if(l==r)
		{
			index[v] = ind;
			value[v] = val;
			number[v] = num;
			return;
		}
		int h = (l+r)/2;
		if(ind<=h) insert(ind,val,num,l,h,2*v);
		else insert(ind,val,num,h+1,r,2*v+1);
		update(v);
	}
	std::pair<int,int> get(int L, int R, int l=1,int r=2*a,int v=1)
	{
		if(L<=l&&r<=R) return std::make_pair(number[v],value[v]);
		else if(R<l) return std::make_pair(0,MAX);
		else if(r<L) return std::make_pair(0,MAX);
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> p1 = get(L,R,l,h,2*v);
			std::pair<int,int> p2 = get(L,R,h+1,r,2*v+1);
			if(p1.second<=p2.second) return p1;
			else return p2;
		}
	}
}T2;


std::pair<int,int> x[300010];
std::vector<int> ans1,ans2;

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].first,&x[i].second);
	
	for(int i=1;i<=2*a;i++) T1.insert(i,0,0);
	for(int i=1;i<=a;i++) if(x[i].first<x[i].second) T1.insert(x[i].first,x[i].second,i);
	
	std::pair<int,int> pivot = T1.get(1,2*a);
	ans1.push_back(pivot.first);
	T1.insert(x[pivot.first].first,0,0);
	while(1)
	{
		std::pair<int,int> p = T1.get(1,pivot.second-1);
		if(p==std::make_pair(0,0)) break;
		ans1.push_back(p.first);
		T1.insert(x[p.first].first,0,0);
		pivot = p;
	}
	
	for(int i=1;i<=2*a;i++) T2.insert(i,MAX,0);
	for(int i=1;i<=a;i++) if(x[i].first>x[i].second) T2.insert(x[i].first,x[i].second,i);
	
	pivot = T2.get(1,2*a);
	ans2.push_back(pivot.first);
	T2.insert(x[pivot.first].first,MAX,0);
	while(1)
	{
		std::pair<int,int> p = T2.get(pivot.second+1,2*a);
		if(p==std::make_pair(0,MAX)) break;
		ans2.push_back(p.first);
		T2.insert(x[p.first].first,MAX,0);
		pivot = p;
	}
	
	if(ans1.size()>=ans2.size())
	{
		printf("%d\n",ans1.size());
		for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]);
		return 0;
	}
	else
	{
		printf("%d\n",ans2.size());
		for(int i=0;i<ans2.size();i++) printf("%d ",ans2[i]);
		return 0;
	}
}