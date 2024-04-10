#include <stdio.h>
#include <stack>
#include <vector>
struct segTree{
	long long int value[4000010];
	long long int lazy[4000010];
	void addValue(int L, int R, long long int val, int l=1, int r=1000001, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v+1] += lazy[v], lazy[2*v] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMax(int L, int R, int l=1, int r=1000001, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v+1] += lazy[v], lazy[2*v] += lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getMax(L,R,l,h,2*v);
			long long int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

int x[1000010];
std::stack<int> St1,St2;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	St1.push(a+1);
	St2.push(a+1);
	for(int i=a;i>=1;i--)
	{
		int p = i;
		while(!St1.empty())
		{
			int t = St1.top();
			T.addValue(p+1,t,x[i]-x[p]);
			p = t;
			if(t==a+1)
			{
				St1.push(i);
				break;
			}
			else
			{
				T.addValue(p+1,t,x[i]-x[p]);
				p = t;
				if(x[t]>=x[i])
				{
					St1.push(i);
					break;
				}
				else St1.pop();
			}
		}
		while(!St2.empty())
		{
			int t = St2.top();
			T.addValue(p+1,t,x[p]-x[i]);
			p = t;
			if(t==a+1)
			{
				St2.push(i);
				break;
			}
			else
			{
				T.addValue(p+1,t,x[p]-x[i]);
				p = t;
				if(x[t]<=x[i])
				{
					St2.push(i);
					break;
				}
				else St2.pop();
			}
		}
		
		long long int s = T.getMax(i+1,a+1);
		//printf("%d %lld!!\n",i,s);
		T.addValue(i,i,s);
	}
	printf("%lld",T.getMax(1,1));
}