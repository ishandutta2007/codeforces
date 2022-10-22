#include<bits/stdc++.h>
using namespace std;
vector<int >v1,v2,v3;
int n,flag;
int main()
{
	cin>>n;
	int t=0;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		if(s1[i]=='1'&&s2[i]=='0')
			v1.push_back(i+1);
		if(s1[i]=='0'&&s2[i]=='1')
			v1.push_back(i+1);
		if(s1[i]=='1'&&s2[i]=='1')
			v2.push_back(i+1);
		if(s1[i]=='0'&&s2[i]=='0')
			v3.push_back(i+1);
		if(s2[i]=='1')
			t++;
	}
	int a=v1.size(),b=v2.size(),c=v3.size();
	for(int i=0;i<=b;i++)
	{
		int x=t-2*i;
		if(x>=0&&n/2-i-x>=0&&x<=a&&n/2-i-x<=c)
		{
			a=x;
			b=i;
			c=n/2-i-x;
			flag=1;
		}
	}
	if(flag)
	{
		for(int i=0;i<a;i++)
			cout<<v1[i]<<" ";
		for(int i=0;i<b;i++)
			cout<<v2[i]<<" ";
		for(int i=0;i<c;i++)
			cout<<v3[i]<<" ";
	}
	else
		cout<<"-1";
	return 0;
}