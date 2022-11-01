#include<bits/stdc++.h>

using namespace std;

int flg[1000005];

set<int> s;

vector<int> p;

set<int> gf(int x)
{
	set<int> ans;
	int i;
	for (i=0;i<p.size()&&p[i]*p[i]<=x;i++)
	{
		if (x%p[i]==0)
		{
			x/=p[i];
			ans.insert(p[i]);
			while (x%p[i]==0) x/=p[i];
		}
	}
	if (x>1)
	{
		ans.insert(x);
	}
	return ans;
}

void ss()
{
	int i,j;
	
	for (i=2;i<=1000000;i++)
	{
		if (!flg[i])
		{
			p.push_back(i);
			for (j=2;i*j<=1000000;j++)
			{
				flg[i*j]=1;
			}
		}
	}
}

int getans(bool dep,int x)
{
	if (dep>1) return x;
	s=gf(x);
	if (s.empty()) return x;
	int t=*s.rbegin();
	if (t==x) return x;
	if (dep==1)
	{
		x-=t;x++;
		return x;
	}
	int mn=x;
	for (int i=x-1;i>x-t;i--)
	{
		mn=min(mn,getans(dep+1,i));
	}
	return mn;
}

int main()
{
	ss();
	
	int n;
	
	scanf("%d",&n);
	
	printf("%d\n",getans(0,n));
	return 0;
}