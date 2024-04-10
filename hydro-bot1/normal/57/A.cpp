// Hydro submission #6247fa650bc575b66aa58900@1648884325808
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x1,x2,y1,y2,a,b;
	cin>>n>>x1>>y1>>x2>>y2;
	a=abs(x1-x2);b=abs(y1-y2);
	x1=(a==n||b==n)?x1+y1+x2+y2:a+b;
	printf("%d\n",min(x1,4*n-x1));
	return 0;
}