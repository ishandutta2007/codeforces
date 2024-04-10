#include<bits/stdc++.h>
using namespace std;
typedef int ll;
struct dragon{
	ll hp,get;
};
ll cnt,tot;
dragon d[100001];
inline bool cmp(dragon a,dragon b)
{
	return a.hp<b.hp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>tot>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>d[i].hp>>d[i].get;
	}
	sort(d,d+cnt,cmp);
	for(register int i=0;i<cnt;i++)
	{
		if(tot<=d[i].hp)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else
		{
			tot+=d[i].get;
		}
	}
	cout<<"YES"<<endl;
}