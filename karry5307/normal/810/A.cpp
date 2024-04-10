#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,tot,maxn,k;
double avg;
int main()
{
	cin>>cnt>>maxn;
	for(register int i=0;i<cnt;i++)
	{
		cin>>tot;
		avg+=tot;
	}
	while(round(avg/(cnt+k))<maxn)
	{
		avg+=maxn;
		k++;
	}
	cout<<k;
}