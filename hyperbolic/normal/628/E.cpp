#include <stdio.h>
#include <vector>
#include <algorithm>

struct segTree{
	int value[12010];
	int lazy[12010];
	void setValue(int L, int R, int val, int l=1, int r=3000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = (r-l+1)*val, lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = (r-h)*lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=3000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = (r-h)*lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

std::vector< std::pair<int,int> > V;
int left[3010][3010],diag[3010][3010],right[3010][3010];
char x[3010][3010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		int p = 1;
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='.') p = j+1;
			else left[i][j] = j-p+1;
		}
	}
	for(int i=1;i<=a;i++)
	{
		int p = b;
		for(int j=b;j>=1;j--)
		{
			if(x[i][j]=='.') p = j-1;
			else right[i][j] = p;
		}
	}
	
	for(int i=2;i<=a+b;i++)
	{
		int p = 1;
		for(int j=1;j<=b;j++)
		{
			if(i-j>a) p = j+1;
			else if(i-j<1) p = j+1;
			else if(x[i-j][j]=='.') p = j+1;
			else diag[i-j][j] = j-p+1;
		}
	}
	
	long long int ans = 0;
	for(int i=2;i<=a+b;i++)
	{
		T.setValue(1,b,0);
		V.clear();
		for(int j=1;j<=b;j++)
		{
			if(i-j>a) continue;
			if(i-j<1) continue;
			if(x[i-j][j]=='z') V.push_back({right[i-j][j],j});
		}
		
		std::sort(V.begin(),V.end());
		for(int j=b;j>=1;j--)
		{
			if(i-j>a) continue;
			if(i-j<1) continue;
			if(x[i-j][j]=='z')
			{
				while(!V.empty()&&V.back().first>=j)
				{
					T.setValue(V.back().second,V.back().second,1);
					V.pop_back();
				}
				int s = left[i-j][j]<diag[i-j][j]?left[i-j][j]:diag[i-j][j];
				ans += T.getSum(j-s+1,j);
			}
		}
	}
	printf("%lld",ans);
}