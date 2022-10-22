#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
bool wyn[100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,l,r,i,j;
	char xd;
	cin>>n;
	l=0;
	r=9;
	for(i=1;i<=n;i++)
	{
		cin>>xd;
		if(xd=='L')
		{
			for(j=0;j>=0;j++)
			{
				if(!wyn[j])
					break;
			}
			wyn[j]=true;
		}
		else if(xd=='R')
		{
			for(j=9;j>=0;j--)
			{
				if(!wyn[j])
					break;
			}
			wyn[j]=true;
		}
		else
		{
			wyn[xd-'0']=0;
		}
	}
	for(i=0;i<=9;i++)
		cout<<wyn[i];
	return 0;
}