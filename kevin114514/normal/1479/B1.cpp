#include<bits/stdc++.h>
using namespace std;
int l1,l2;
int c[100100];
int nxt[100100];
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++)
		cin>>c[i];
	for(int i=n-1;i>=0;i--)
		if(c[i]==c[i+1])
			nxt[i]=nxt[i+1];
		else	nxt[i]=c[i+1];
	for(int i=0;i<n;i++)
	{
		int x=c[i];
		if(l1==x)
		{
			if(l2!=x)
			{
				l2=x;
				ans++;
			}
		}
		if(l2==x)
		{
			if(l1!=x)
			{
				l1=x;
				ans++;
			}
		}
		if(l1!=x&&l2!=x)
		{
			if(l1==nxt[i])
			{
				l1=x;
				ans++;
			}
			else
			{
				l2=x;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}