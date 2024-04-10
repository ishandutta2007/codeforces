#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n,i,j,s,ans,a[MAXN],b[MAXN];
map<pair<int,int>,int> m;
int gcd(int x,int y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	for(i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			a[i]=-a[i];
			b[i]=-b[i];
		}
		j=gcd(a[i],max(-b[i],b[i]));
		if(j){
		a[i]/=j;
			b[i]/=j;}
		if(a[i])ans=max(ans,++m[make_pair(a[i],b[i])]);
		else s+=!b[i];
	}
	cout<<s+ans<<endl;
	return 0;
}