#include<bits/stdc++.h>
using namespace std;
int q[50001];
struct node
{
	int p,t;
}a[50001];
bool ccmp(node a,node b)
{
	if(a.p!=b.p)
	return a.p<b.p;
	else return a.t<b.t;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p;
		a[i].t=i;
	}
	sort(a,a+n+1,ccmp);
	int ans=0;
	for(int i=n;i>=(n-k+1);i--)
	{
	//	cout<<a[i].t<<"*";
		ans+=a[i].p;
		q[a[i].t]++;
	}
	cout<<ans<<endl;
	int te1=1,te2=1;
	q[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(q[i]==0)
		{
			te1++;
		}
		else if(q[i]!=0 && te2<k)
		{
			te2++;
			cout<<te1<<' ';
			te1=1;
		}
		else if(q[i]!=0 && te2==k )
		{
			te1++;
		}
		
	}
	cout<<te1-1<<endl;
	
}