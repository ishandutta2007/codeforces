// Hydro submission #6253c4e148f7830132791ca2@1649657057727
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int i,n,b,mx=0;
    double x;
    cin>>n>>b;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b+=a[i];
		if(mx<a[i])
		mx=a[i];
	}
	x=b*1.0/n;
	if(x<mx)
	printf("-1\n");
	else for(i=0;i<n;i++)
	printf("%.6lf\n",x-a[i]);
    return 0;
}