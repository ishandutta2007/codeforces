#include<bits/stdc++.h>
using namespace std;
unsigned long long int pre,last,x;
map<unsigned long long int,bool>mp;
inline void setup()
{
	pre=1;
	mp[1]=1;
	last=1;
	for(register int i=3;i<=40;i++)
	{
		x=last;
		last+=pre;
		pre=x;
		mp[last]=1;
	}
}
int main()
{
	setup();
	cin>>x;
	for(register int i=1;i<=x;i++)
	{
		if(mp[i]==1)
		{
			cout<<'O';
		}
		else
		{
			cout<<'o';
		}
	}
}