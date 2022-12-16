#include<bits/stdc++.h>
using namespace std;
long long n,k,tn;
int i;
long long cnt(long long i,long long a,long long b,long long c,bool flag)
{
	long long s=0;
	if(flag)
	{
		if(i==c||i==c+1)
			s+=a;
		if(i+1==c||i==c)
			s+=b;
	}
	else
	{
		if(i==c)
			s+=a;
		if(i+1==c)
			s+=b;
	}
	if(i==0)
		return s;
	if(i&1)
		s+=cnt(i/2,a*2+b,b,c,flag);
	else
		s+=cnt(i/2-1,a,a+2*b,c,flag);
	return s;
}
long long cnt12(long long i,long long a,long long b)
{
	if(i==1)
		return a+b*2;
	long long s=0;
	if(i==2)
	{
		s=a*2;
		++i;
		a=b;
		b=0;
	}
	if(i&1)
		s+=cnt12(i/2,a*2+b,b);
	else
		s+=cnt12(i/2-1,a,a+2*b);
	return s;
}
long long Findkc(long long i,long long l,long long r,long long k,long long c,bool flag)
{
	if(r-l+1<=c+flag)
		return (l+r>>1);
	long long mid=l+r>>1;
	if(i&1)
	{
		long long m=cnt(i/2,1,0,c,flag);
		if(k<=m)
			return Findkc(i/2,l,mid-1,k,c,flag);
		else
			return Findkc(i/2,mid+1,r,k-m,c,flag);
	}
	else
	{
		long long m=cnt(i/2-1,1,0,c,flag);
		if(k<=m)
			return Findkc(i/2-1,l,mid-1,k,c,flag);
		else
			return Findkc(i/2,mid+1,r,k-m,c,flag);
	}
}
long long Find2(long long i,long long l,long long r,long long k)
{
	if(r-l+1<=2)
		return l+k-1;
	long long mid=l+r>>1;
	if(i&1)
	{
		long long m=cnt12(i/2,1,0);
		if(k<=m)
			return Find2(i/2,l,mid-1,k);
		else
			return Find2(i/2,mid+1,r,k-m);
	}
	else
	{
		long long m=cnt12(i/2-1,1,0);
		if(k<=m)
			return Find2(i/2-1,l,mid-1,k);
		else
			return Find2(i/2,mid+1,r,k-m);
	}
}
long long Findans(long long n,long long k,long long a,long long b)
{
	if(n==1||n==2)
	{
		if(k<=b&&n==2)
			return Findkc(tn-2,2,tn-1,k,n+1,false);
		return Find2(tn-2,2,tn-1,k-(n==2?b:0));
	}
	if(n&1)
	{
		if(k<=a+b)
			return Findkc(tn-2,2,tn-1,k,n,true);
	}
	else
		if(k<=a+b)
			if(k<=b)
				return Findkc(tn-2,2,tn-1,k,n+1,false);
			else
				return Findkc(tn-2,2,tn-1,k-b,n,false);
	if(n&1)
		return Findans(n/2,k-a-b,a*2+b,b);
	else
		return Findans(n/2-1,k-a-b,a,a+b*2);
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin>>n>>k;
	if(k==1)
	{
		cout<<1;
		return 0;
	}
	if(k==2)
	{
		cout<<n;
		return 0;
	}
	tn=n;
	n-=2;
	k-=2;
	cout<<Findans(n,k,1,0);
}