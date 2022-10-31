// Hydro submission #631f31fdbdf9bc31d15c873d@1662988798792
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;cin>>n;
	n%=360;if(n<0) n+=360;
	m=n/90;n-=m*90;
	if(n>45) printf("%lld\n",(m+1)%4);
	else if(n<45) printf("%lld\n",m%4);
	else printf("%lld\n",min((m+1)%4,m%4));
	return 0;
}