#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,tot[1000001],now;
double avg;
inline ll add()
{
	ll res=0;
	for(register int i=0;i<cnt;i++)
	{
		res+=tot[i];
	}
	return res;
}
int main()
{
	cin>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>tot[i];
	}
	sort(tot,tot+cnt);
	while(round(add()/(double)(cnt))<5)
	{
		tot[now++]=5;
	}
	cout<<now;
}