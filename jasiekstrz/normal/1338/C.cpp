#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
long long f(long long x,int t)
{
	if(x==1)
		return (t==0 ? 3:2);
	long long ans=4LL*f(x/4,t);
	if(x%4==0);
	if(x%4==1)
	{
		if(t==2)
			ans+=2;
		else 
			ans+=3;
	}
	if(x%4==2)
	{
		if(t==2)
			ans+=3;
		else 
			ans+=1;
	}
	if(x%4==3)
	{
		if(t==2)
			ans+=1;
		else 
			ans+=2;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long q,n,i;
	cin>>q;
	while(q--)
	{
		cin>>n;
		long long k=(n+2)/3;
		long long xd=0,pot;
		for(pot=1;xd+pot<k;xd+=pot,pot*=4);
		for(i=pot,xd++;xd<k;xd++,i++);
		if(n%3==1)
			cout<<i<<"\n";
		else
			cout<<f(i,n%3)<<"\n";
	}
	return 0;
}