#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,p,m,x;
int get(int x)
{
	if(!x)return 0;
	return get(x>>1)+(x&1);
}
int main()
{
	cin>>n>>p;
	for(m=1;m<=30;m++)
	{
		x=n-m*p;
		if(x>=m&&get(x)<=m)
		{
			cout<<m<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}