// Hydro submission #62e244e0c21c1686c7279a81@1658995936890
#include<bits/stdc++.h>
using namespace std;
long long s=1,r;
void d(int a,int b,int c,int l)
{
	int mn,i;r=0;
	for(i=max(0,a+b-c);i<=l;i++)
	{
		mn=min(l-i,c+i-a-b);
		r+=1ll*(mn+1)*(mn+2)/2;
	}
	s-=r;
}
int main()
{
	int a,b,c,l,i;
	cin>>a>>b>>c>>l;
	for(i=1;i<=l;i++)
	s+=1ll*(i+1)*(i+2)/2;
	d(a,b,c,l);
	d(a,c,b,l);
	d(b,c,a,l);
	printf("%lld\n",s);
	return 0;
}