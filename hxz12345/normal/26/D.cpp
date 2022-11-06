#include<bits/stdc++.h>
using namespace std;
long long i,n,m,k;
double x;
int main()
{
	cin>>n>>m>>k;
	if (k>=m){puts("1.0000");return 0;}
	if (n+k<m)
	    {
	    	puts("0.0000");return 0;
		}
    x=1;
	for (i=1;i<=k+1;i++)
	    	x=x*(m-k+i-1)/(n+i);
	printf("%.6lf\n",1-x);
	return 0;
}