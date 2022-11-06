#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string n;
	cin>>n;
	bool f=1;
	int s=n.size(),t;
	if(n[s-1]%2==0)
	{
		int m=-1,p=0;
		for(int i=0;i<s-1;i++)
		{
			if(n[i]>=m)
			{
				m=n[i];
				p=i;
			}
		}
		int i=0;
		if(n[s-1]>m && n[0]%2==0)
		{
			t=n[s-1];
			n[s-1]=n[0];
			n[0]=t;
		}
		else
		{
			while(n[i]==m)
			i++;
			if(n[i]%2==0 && n[s-1]==m)
			p=s-1;
			t=n[i];
			n[i]=n[p];
			n[p]=t;
		}
	}
	else
	{
		int p=0;
		for(int i=0;i<s-1;i++)
		{
			if(n[i]%2==0)
			{
				f=0;
				p=i;
				if(n[i]<n[s-1])
				{
					break;	
				}
			}
			
		}
		t=n[p];
		n[p]=n[s-1];
		n[s-1]=t;
	}
	if(f)
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<s;i++)
	cout<<n[i];
	return 0;
}