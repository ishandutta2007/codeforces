#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX (long long int )1e16

struct segTree{
	int value[400010];
	void setValue(int ind, int val, int l=1, int r=100000, int v=1)
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
	int getSum(int L, int R, int l=1, int r=100000, int v=1)
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

std::vector<int> V[30];
char x[100010],y[100010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		for(int i=0;i<26;i++) V[i].clear();
		
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		for(int i=1;i<=a;i++) T.setValue(i,1);
		for(int i=1;i<=a;i++) V[x[i]-'a'].push_back(i);
		for(int i=0;i<26;i++) std::reverse(V[i].begin(),V[i].end());
		
		long long int ans = MAX;
		long long int sum = 0;
		int p = 1;
		for(int i=1;i<=a;i++)
		{
			while(T.getSum(p,p)==0) p++;
			if(V[x[p]-'a'].back()==p) V[x[p]-'a'].pop_back();
			
			if(x[p]==y[i])
			{
				for(int j=0;j<y[i]-'a';j++)
				{
					if(!V[j].empty())
					{
						int t = V[j].back();
						long long int val = sum + T.getSum(p+1,t);
						ans = ans<val?ans:val;
					}
				}
				p++;
			}
			else if(x[p]<y[i])
			{
				ans = ans<sum?ans:sum;
				break;
			}
			else
			{
				for(int j=0;j<y[i]-'a';j++)
				{
					if(!V[j].empty())
					{
						int t = V[j].back();
						long long int val = sum + T.getSum(p+1,t);
						ans = ans<val?ans:val;
					}
				}
				
				if(!V[y[i]-'a'].empty())
				{
					int t = V[y[i]-'a'].back();
					sum += T.getSum(p+1,t);
					T.setValue(t,0);
					V[y[i]-'a'].pop_back();
				}
				else break;
			}
		}
		
		if(ans==MAX) printf("-1\n");
		else printf("%lld\n",ans);
	}
}