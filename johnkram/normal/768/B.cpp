#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100],s[100],l,r,i;
ll work1(ll i,ll l)
{
	if(!l)return 0;
	if(l>=s[i+1])return work1(i+1,l-s[i+1])+a[i+1]+(a[i]&1);
	return work1(i+1,l);
}
ll work2(ll i,ll r)
{
	if(r==s[i])return 0;
	if(r<=s[i+1])return work2(i+1,r)+a[i+1]+(a[i]&1);
	return work2(i+1,r-s[i+1]);
}
ll work(ll i,ll l,ll r)
{
	if(r<s[i+1])return work(i+1,l,r);
	if(l>s[i+1])return work(i+1,l-s[i+1],r-s[i+1]);
	return work2(i+1,l)+work1(i+1,r-s[i+1])+(a[i]&1);
}
int main()
{
	cin>>n>>l>>r;
	for(a[0]=n,i=1;a[i-1]>1;i++)a[i]=a[i-1]>>1;
	for(s[i--]=1;~i;i--)s[i]=s[i+1]<<1;
	cout<<work(0,l,r);
	return 0;
}