#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define ll long long
set<int> x,y,z;
set<int>::iterator l,r,it;
int n,i,ans=1;
char c[10];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%d",c,&i);
		if(c[1]=='D')if(!x.empty()&&i<*l)
		{
			x.insert(i);
			l=x.end();
			l--;
		}
		else if(!y.empty()&&i>*r)
		{
			y.insert(i);
			r=y.begin();
		}
		else z.insert(i);
		else if(!x.empty()&&i<=*l)
		{
			if(i<*l)
			{
				ans=0;
				break;
			}
			for(it=z.begin();it!=z.end();it++)y.insert(*it);
			z.clear();
			x.erase(l);
			l=x.end();
			r=y.begin();
			if(!x.empty())l--;
		}
		else if(!y.empty()&&i>=*r)
		{
			if(i>*r)
			{
				ans=0;
				break;
			}
			for(it=z.begin();it!=z.end();it++)x.insert(*it);
			z.clear();
			y.erase(r);
			l=x.end();
			r=y.begin();
			if(!x.empty())l--;
		}
		else
		{
			for(it=z.begin();it!=z.end();it++)if(*it<i)x.insert(*it);
			else if(*it>i)y.insert(*it);
			z.clear();
			ans<<=1;
			if(ans>=P)ans-=P;
			l=x.end();
			r=y.begin();
			if(!x.empty())l--;
		}
	}
	ans=(ll)ans*(z.size()+1)%P;
	cout<<ans<<endl;
	return 0;
}