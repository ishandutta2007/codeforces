#include<bits/stdc++.h>
using namespace std;
int s[101],n,x,y,maxc=-99999;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=1;i<n;i++)
		s[i]+=s[i-1];
	for(int i=0;i<n;i++)
	{
		x=i-0+1,y=x-s[i];
		maxc=max(maxc,2*y-x);
	}
	for(int i=1;i<n;i++)
		for(int j=i;j<n;j++)
		{
			x=j-i+1,y=x-(s[j]-s[i-1]);
			maxc=max(maxc,2*y-x);
		}
	cout<<maxc+s[n-1];
	return 0;
}