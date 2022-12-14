#include <stdio.h>
#define MOD 1000000007

struct segTree{
	long long int value[4000010];
	void setValue(int ind, long long int val, int l=1, int r=1000000, int v=1)
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
	long long int getSum(int L, int R, int l=1, int r=1000000, int v=1)
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


long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int left[1000010],right[1000010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		
		if(a==1)
		{
			printf("1\n");
			continue;
		}
		
		
		int p = a/2;
		for(int i=p+1;i<=a;i++) T.setValue(i,inv(power(2,i)));
		for(int i=p;i>=2;i--)
		{
			long long int val = T.getSum(i+1,2*i-1);
			T.setValue(i,val);
		}
		T.setValue(1,0);
		
		for(int i=1;i<=a;i++) right[i] = (T.getSum(i,i)*power(2,i))%MOD;
		
		for(int i=2;i<=a;i++)
		{
			int p = i/2;
			left[i] = inv(power(2,(i-p+1)));
		}
		left[a]*=2, left[a] %= MOD;
		
		
		for(int i=1;i<=a;i++) printf("%lld\n",(2*left[i]*right[i])%MOD);
	}
}