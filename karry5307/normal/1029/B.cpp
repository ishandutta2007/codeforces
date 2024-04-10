#include<bits/stdc++.h>
using namespace std;
typedef int ll;
struct interval{
	ll l,r,size;
};
const ll MAXN=1e5+51;
interval inte[MAXN];
ll num,cnt,ccnt,maxn;
int main()
{
	cin>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>num;
		if(num>inte[ccnt].r)
		{
			inte[++ccnt].l=num,inte[ccnt].r=num*2,inte[ccnt].size=1;
		}
		else
		{
			inte[ccnt].r=num*2,inte[ccnt].size++;
		}
	}
	for(register int i=1;i<=ccnt;i++)
	{
		maxn=max(maxn,inte[i].size);
	}
	cout<<maxn;
}