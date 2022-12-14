#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX (long long int)1e18
#define MIN -(long long int)1e18

struct segTree1{
	long long int value[810010];
	void setValue(int ind, long long int val, int l=0, int r=200001, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMax(int L,int R, int l=0, int r=200001, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MIN;
		else if(R<l) return MIN;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getMax(L,R,l,h,2*v);
			long long int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}S1,T1;

struct segTree2{
	long long int value[800010];
	void setValue(int ind, long long int val, int l=0, int r=200001, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMin(int L,int R, int l=0, int r=200001, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getMin(L,R,l,h,2*v);
			long long int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}S2,T2;

int x[200010];
long long int sum[200010];
std::vector< std::pair<int,int> > V;
int left[200010],right[200010];

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
		
		for(int i=0;i<=a;i++) T1.setValue(i,sum[i]);
		for(int i=0;i<=a;i++) T2.setValue(i,sum[i]);
		for(int i=0;i<=a+1;i++) S1.setValue(i,MIN);
		for(int i=0;i<=a+1;i++) S2.setValue(i,MAX);
		S1.setValue(0,0);
		S2.setValue(a+1,a+1);
		
		for(int i=1;i<=a;i++) V.push_back(std::make_pair(x[i],i));
		std::sort(V.begin(),V.end());
		std::reverse(V.begin(),V.end());
		for(int i=0;i<V.size();i++)
		{
			int t = V[i].second;
			right[t] = S2.getMin(t+1,a+1);
			left[t] = S1.getMax(0,t-1);
			S2.setValue(t,t);
			S1.setValue(t,t);
		}
		
		for(int i=1;i<=a;i++)
		{
			long long int s1 = T1.getMax(i,right[i]-1) - sum[i-1];
			long long int s2 = sum[i] - T2.getMin(left[i],i-1);
			if(s1+s2-x[i]>x[i])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}