// Hydro submission #6253b37848f7830132791293@1649652601657
#include<bits/stdc++.h> 
using namespace std;
long long a[3],k,x,y,z;
int main()
{
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	cin>>k;
	sort(a,a+3);
	if(k/3<=a[0])
	{
		x=k/3;
		y=(k-x)/2;
	}
	else
	{
		x=a[0];
		if((k-x)/2<=a[1])y=(k-x)/2;
		else y=a[1];
	} 
	if(k-y-x<=a[2])z=k-y-x;
	else z=a[2];
	printf("%lld\n",(x+1)*(y+1)*(z+1));
	return 0;
}