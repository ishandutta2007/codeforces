#include <stdio.h>
#include <vector>
#include <map>
#define MOD 1000000007

struct segTree{
	std::pair<int,int> value[800010];
	void setValue(int ind, std::pair<int,int> val,int l=1, int r=200000, int v=1)
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
	std::pair<int,int> getMax(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return std::make_pair(0,0);
		else if(R<l) return std::make_pair(0,0);
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> s1 = getMax(L,R,l,h,2*v);
			std::pair<int,int> s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

int a,b;
int x[200010];
std::vector<long long int> func(int L, int R)
{
	if(L>R)
	{
		std::vector<long long int> ans;
		for(int i=0;i<=b;i++) ans.push_back(1);
		return ans;
	}
	
	int h = -T.getMax(L,R).second;
	std::vector<long long int> value(b+1),value2(b+1),value3(b+1),temp(b+1);
	value = func(h+1,R);
	temp = func(L,h-1);
	for(int i=1;i<=b;i++) value2[i] = temp[i-1];
	for(int i=1;i<=b;i++) value3[i] = value[i]*value2[i], value3[i] %= MOD;
	for(int i=1;i<=b;i++) value3[i] += value3[i-1], value3[i] %= MOD;
	return value3;
}

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) T.setValue(i,std::make_pair(x[i],-i));
		
		std::vector<long long int> ans = func(1,a);
		printf("%lld\n",ans[b]);
	}
}