#include<bits/stdc++.h>
using namespace std;

int n,s,h,m,a,b;

int main()
{
	for(cin>>n>>s,a=0,b=-s-1;n--;)
	{
		cin>>h>>m;
		if((h-a)*60+m-b>=2*s+2) break;
		a=h;b=m;
	}
	cout<<a+(b+s+1)/60<<" "<<(s+b+1)%60;
	return 0;
}