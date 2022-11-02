#include<bits/stdc++.h>
using namespace std;
bool isint(int a)
{
	return (int)(sqrt(a))==sqrt(a);
}
int num,k[1000000];
bool used;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	cin>>num;
	for(register int i=0;i<num;i++)
	{
		cin>>k[i];
	}
	sort(k,k+num,cmp);
	for(register int i=0;i<num;i++)
	{
		if(!used&&!isint(k[i]))
		{
			used=1;
			cout<<k[i];
		}
		if(used)
		{
			return 0;
		}
	}
}