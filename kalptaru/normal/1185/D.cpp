#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
ll max(ll i,ll j)
{
	if(i>j)
	return i;
	return j;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,v;
	cin>>n;
	ll b[n],s[n],c,d,e,f,ans;
	bool a=1;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		s[i]=b[i];
	}
	if(n<4)
	{
		ans=b[0];
	}
	else
	{
		
		sort(b,b+n);
		c=b[1]-b[0];
		d=b[2]-b[1];
		e=b[3]-b[2];
		ans=b[0];
		bool flag=1;
		if(d==c)
		{
			v=3;
		}
		else if(c==d+e)
		{
			v=4;
			flag=0;
			ans=b[2];
			d=c;
		}
		else if(e==c+d)
		{
			v=4;
			flag=0;
			ans=b[1];
			d=e;
		}
		else if(d==e)
		{
			v=4;
			flag=0;
			ans=b[0];
		}
		else
		{
			v=n;
			a=0;
		}
		for(int i=v;i<n;i++)
		{
			if(b[i]-b[i-1]!=d)
			{
				if(flag)
				{
					if(i<n-1)
					{
						if(b[i+1]-b[i-1]==d)
						{
							i++;
							flag=0;
							ans=b[i-1];
						}
						else
						{
							a=0;
							break;
						}
					}
					else
					ans=b[i];
				}
				else
				{
					a=0;
					break;
				}
			}	
		}
	}
	if(a)
	{
		for(int i=0;i<n;i++)
		{
			if(ans==s[i])
			{
				ans=i+1;
				break;
			}
		}
	}
	else
	ans=(-1);
	cout<<ans;
	return 0;
}