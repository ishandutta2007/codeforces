#include<bits/stdc++.h>
using namespace std;
long long r;
int main()
{
	cin>>r;
	--r;
	if(!r)
	{
		puts("NO");
		return 0;
	}
	for(long long x=1;x*x<=r;x++)
	{
		if(r%x)
			continue;
		long long y=r/x;
		--y;
		y-=x;
		if(y%2)
			continue;
		y/=2;
		if(y<=0)
			continue;
		cout<<x<<" "<<y<<endl;
		return 0;
	}
	puts("NO");
	return 0;
}