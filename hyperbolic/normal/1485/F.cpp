#include <stdio.h>
#include <map>
#define MOD 1000000007
struct segTree{
	long long int value[800010];
	void setValue(int ind ,long long int val, int l=0, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = (value[2*v]+value[2*v+1])%MOD;
		}
	}
	long long int getSum(int L, int R, int l=0, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return (s1+s2)%MOD;
		}
	}
}T;

std::map<long long int,long long int> M,save;
long long int x[200010];
long long int y[200010];
int prev[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a;i++) T.setValue(i,0);
		M.clear();
		save.clear();
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=a;i++) y[i] = y[i-1]+x[i];
		
		T.setValue(1,1);
		save[0] = 1;
		for(int i=2;i<=a;i++)
		{
			long long int val = T.getSum(1,i-1);
			val -= save[y[i-1]];
			val += MOD;
			val %= MOD;
			T.setValue(i,val);
			save[y[i-1]] += val;
			save[y[i-1]] %= MOD;
		}
		printf("%lld\n",T.getSum(1,a));
	}
}