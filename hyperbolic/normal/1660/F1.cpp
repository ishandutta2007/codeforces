#include <stdio.h>
#include <vector>

struct segTree{
	int value[800010];
	void addValue(int ind ,int val, int l=0, int r=200000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=0, int r=200000, int v=1)
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
}T[4];

std::vector<int> V;
char x[200010];
int y[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='+') y[i] = 1;
			else y[i] = -1;
		}
		
		long long int ans = 0;
		int C = 200000;
		T[200000%3].addValue(200000/3,1);
		for(int i=1;i<=a;i++)
		{
			C += y[i];
			ans += T[C%3].getSum(C/3,200000);
			T[C%3].addValue(C/3,1);
			V.push_back(C);
		}
		printf("%lld\n",ans);
		for(int i=0;i<V.size();i++) T[V[i]%3].addValue(V[i]/3,-1);
		T[200000%3].addValue(200000/3,-1);
		V.clear();
	}
}