#include <stdio.h>
#define MOD 1000000007

struct segTree{
	long long int value[8010];
	void setValue(int ind, long long int val, int l=1, int r=2000, int v=1)
	{
		if(l==r) value[v] += val, value[v] %= MOD;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1], value[v] %= MOD;
		}
	}
	long long int getSum(int L, int R, int l=1, int r=2000, int v=1)
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
}T[2010];

char x[2010][2010];
int down[2010][2010],right[2010][2010];

long long int sum[2010],DP1[2010][2010],DP2[2010][2010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	for(int i=1;i<=a;i++) for(int j=b;j>=1;j--) right[i][j] = right[i][j+1] + (x[i][j]=='R'?1:0);
	for(int j=1;j<=b;j++) for(int i=a;i>=1;i--) down[i][j] = down[i+1][j] + (x[i][j]=='R'?1:0);
	
	for(int j=1;j<=b;j++) if(right[a][j+1]==0) T[j].setValue(a,1);
	for(int i=a-1;i>=1;i--)
	{
		for(int j=b;j>=1;j--) DP1[i][j] = T[j].getSum(i+1,a-down[i+1][j]);
		for(int j=b;j>=1;j--) sum[j] = (sum[j+1] + DP1[i][j])%MOD;
		
		for(int j=b;j>=1;j--) DP2[i][j] = (sum[j+1] - sum[b-right[i][j+1]+1] + MOD)%MOD;
		
		for(int j=b;j>=1;j--) T[j].setValue(i,DP2[i][j]);
	}
	printf("%lld",T[1].getSum(1,a-down[2][1]));
}