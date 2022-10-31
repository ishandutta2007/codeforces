// Hydro submission #6247f24c0bc575b66aa57a3f@1648882252714
#include<bits/stdc++.h>
using namespace std;
int main()
{
	double l,d,v,g,r,t,s;
	cin>>l>>d>>v>>g>>r;
	t=d/v;s=g+r;
	while(t>s) t-=s;
	if(t<g)
	printf("%.8lf\n",l/v);
	else
	printf("%.8lf\n",l/v+s-t);
	return 0;
}