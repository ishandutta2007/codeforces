#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,m,c,mw,cw;
int main()
{
	ios::sync_with_stdio(false);
	cin>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>m>>c;
		if(m>c)
		{
			mw++;
		}
		if(c>m)
		{
			cw++;
		}
	}
	if(mw>cw)
	{
		cout<<"Mishka";
	}
	if(mw<cw)
	{
		cout<<"Chris";
	}
	if(mw==cw)
	{
		cout<<"Friendship is magic!^^";
	}
	cout<<endl;
}