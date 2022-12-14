#include <stdio.h>
#define MAX 1234567890

struct segTree{
	long long int lazy[1050010];
	long long int value[1050010];
	void update(int v)
	{
		value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
	}
	void add(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L>R) return;
		if(L<=l&&r<=R)
		{
			value[v] += val;
			lazy[v] += val;
		}
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			lazy[2*v] += lazy[v], value[2*v] += lazy[v];
			lazy[2*v+1] += lazy[v], value[2*v+1] += lazy[v];
			lazy[v] = 0;
			
			add(L,R,val,l,h,2*v);
			add(L,R,val,h+1,r,2*v+1);
			update(v);
		}
	}
	long long int getValue(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L>R) return MAX;
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			lazy[2*v] += lazy[v], value[2*v] += lazy[v];
			lazy[2*v+1] += lazy[v], value[2*v+1] += lazy[v];
			lazy[v] = 0;
			
			long long int s1 = getValue(L,R,l,h,2*v);
			long long int s2 = getValue(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

//h~ A
//~h+1
//S[h] = A[h+1:] + B[:h-1]
// Pivot : P
// S[P+1:] <= -=value[P]
// S[:P-1] <= +=value[P]

int x[200010],y[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	T.add(1,x[1]-1,y[1]);
	for(int i=2;i<=a;i++) T.add(x[i]+1,a,y[i]);
	
	long long int ans = T.getValue(1,a);
	ans = ans<y[1]?ans:y[1];
	ans = ans<y[a]?ans:y[a];
	
	for(int i=2;i<a;i++)
	{
		T.add(x[i]+1,a,-y[i]);
		T.add(1,x[i]-1,y[i]);
		long long int s = T.getValue(1,a);
		ans = ans<s?ans:s;
	}
	printf("%lld",ans);
	
}