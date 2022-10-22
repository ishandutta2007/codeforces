#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100];
int n,m,i,p[100];
bool cmp(int x,int y)
{
	if((a[x]<<y)==(a[y]<<x))return x<y;
	return (a[x]<<y)<(a[y]<<x);
}
ll work(int x,int m)
{
	if(!m)return 0;
	ll s=((m-1>>p[x])+1)*a[p[x]];
	if(x<n)s=min(s,(m>>p[x])*a[p[x]]+work(x+1,m&((1<<p[x])-1)));
	return s;
}
int main()
{
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++)p[i]=i;
	sort(p,p+n,cmp);
	cout<<work(0,m)<<endl;
	return 0;
}