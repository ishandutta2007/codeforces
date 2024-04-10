#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,l,r,l1,r1,L,mid;
int m,i,j,N=4500;
char c[10];
double p[100],q[100],P;
bool ask(ll l,ll r)
{
	if(!N)exit(0);
	cout<<l<<' '<<r<<endl;
	fflush(stdout);
	cin>>c;
	N--;
	return c[0]=='Y';
}
int main()
{
	srand(20000116);
	cin>>n>>m;
	l=1;
	r=n;
	while(r-l+1>4*m)
	{
		mid=l+r>>1;
		if(ask(l,mid))
		{
			r=mid;
			if(l==r)return 0;
		}
		else l=mid+1;
		l=max(1LL,l-m);
		r=min(n,r+m);
	}
	for(;N>1;)
	{
	mid=rand()%(r-l+1)+l; 
	if(ask(mid,mid))return 0;
	else
	{
		l=max(1LL,l-m);
		r=min(n,r+m);
	}
	while(r-l+1>4*m)
	{
		mid=l+r>>1;
		if(ask(l,mid))
		{
			r=mid;
			if(l==r)return 0;
		}
		else l=mid+1;
		l=max(1LL,l-m);
		r=min(n,r+m);
	}
	}
	ask(l,l);
	return 0;
}