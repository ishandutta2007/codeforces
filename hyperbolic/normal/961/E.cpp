#include <stdio.h>
#include <set>

struct segTree{
	int value[800010];
	void setValue(int ind ,int val, int l=1, int r=200000, int v=1)
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
	int getSum(int L, int R, int l=1, int r=200000, int v=1)
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

std::set< std::pair<int,int> > save;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) T.setValue(i,0);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		int limit = i-1<b?i-1:b;
		ans += T.getSum(1,limit);
		
		if(b>=i+1)
		{
			T.setValue(i,1);
			save.insert({b,i});
		}
		while(!save.empty())
		{
			std::set< std::pair<int,int> > ::iterator it = save.begin();
			if(it->first==i)
			{
				T.setValue(it->second,0);
				save.erase(it);
			}
			else break;
		}
	}
	printf("%lld",ans);
}