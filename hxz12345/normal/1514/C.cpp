#include<bits/stdc++.h>
using namespace std;
long long  ans,w,n,x,i,b[100010];
int gcd(int x,int y)
{
	if (y==0) return x;
	int ans=gcd(y,x % y);return ans;
}
int main()
{
	cin>>n;x=1;
	for (i=1;i<=n;i++)
	   if (gcd(i,n)==1)
	       {
	       	w++;b[w]=i;
	       	x=x*i % n;
	       	if (x==1) ans=w;
		   }
	cout<<ans<<endl;
    for (i=1;i<=ans;i++) cout<<b[i]<<" ";
	return 0;
}