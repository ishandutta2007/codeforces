#include <stdio.h>
#include <queue>
#include <vector>

struct segTree{
	int value[800010];
	void setValue(int ind, int val, int l=1, int r=200000 ,int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
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
			return getSum(L,R,l,h,2*v) + getSum(L,R,h+1,r,2*v+1);
		}
	}
}T;

std::priority_queue<int> Q1;
std::priority_queue<int, std::vector<int>, std::greater<int> > Q2;
long long int count[200010];
int x[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		x[b] = i;
	}
	
	for(int i=1;i<=a;i++)
	{
		count[i] = T.getSum(x[i]+1,a);
		T.setValue(x[i],1);
	}
	for(int i=2;i<=a;i++) count[i] += count[i-1];
	
	printf("0 ");
	long long int ans = x[1];
	Q2.push(x[1]);
	
	for(int i=2;i<=a;i++)
	{
		if(Q2.top()<=x[i])
		{
			Q2.push(x[i]);
			ans += x[i];
			if(Q2.size()>=2+Q1.size())
			{
				int k = Q2.top();
				ans -= 2*k;
				Q2.pop();
				Q1.push(k);
			}
		}
		else
		{
			Q1.push(x[i]);
			ans -= x[i];
			if(Q1.size()>=1+Q2.size())
			{
				int k = Q1.top();
				ans += 2*k;
				Q1.pop();
				Q2.push(k);
			}
		}
		
		long long int ans2 = 0;
		long long int k = Q1.size();
		ans2 -= (k+1)*(k)/2;
		k = Q2.size();
		ans2 -= (k-1)*(k)/2;
		
		if(i%2==0) printf("%lld ",count[i] + ans + ans2);
		else printf("%lld ",count[i]+ans + ans2 - Q2.top());
	}
}