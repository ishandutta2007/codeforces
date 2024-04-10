#include<bits/stdc++.h>
#define ll long long
ll n;
int t,a,b,l,r,mid,c;
int gcd(int x,int y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		n=(ll)a*b;
		l=1;
		r=1000001;
		while(l+1<r)
		{
			mid=l+r>>1;
			if((ll)mid*mid*mid<=n)l=mid;
			else r=mid;
		}
		if((ll)l*l*l!=n||gcd(a,b)%l)puts("No");
		else puts("Yes");
	}
	return 0;
}