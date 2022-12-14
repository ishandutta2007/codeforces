#include <stdio.h>
#define MOD 998244353

struct segTree1{
	long long int value[800010];
	void setValue(int ind, long long int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = (value[2*v]*value[2*v+1])%MOD;
		}
	}
	long long int getMul(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 1;
		else if(R<l) return 1;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getMul(L,R,l,h,2*v);
			long long int s2 = getMul(L,R,h+1,r,2*v+1);
			return (s1*s2)%MOD;
		}
	}
}T1;

struct segTree2{
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
}T2;

long long int fact[200010];
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

int x[200010],y[200010];
int count[200010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	
	for(int i=1;i<=a;i++) count[x[i]]++;
	for(int i=1;i<=200000;i++) T1.setValue(i,fact[count[i]]);
	for(int i=1;i<=200000;i++) T2.setValue(i,count[i]);
	
	int S = a;
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		if(S==0)
		{
			ans++, ans%=MOD;
			break;
		}
		long long int val = fact[S-1];
		long long int s1 = T1.getMul(1,200000);
		int s2 = T2.getSum(1,y[i]-1);
		val *= inv(s1), val %= MOD;
		val *= s2, val %= MOD;
		ans += val, ans %= MOD;
		
		if(count[y[i]]>0)
		{
			S--;
			count[y[i]]--;
			T1.setValue(y[i],fact[count[y[i]]]);
			T2.setValue(y[i],count[y[i]]);
		}
		else break;
	}
	
	printf("%lld",ans);
}