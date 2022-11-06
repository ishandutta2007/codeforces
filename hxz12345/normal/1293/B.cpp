#include<bits/stdc++.h>
using namespace std;
int n,i;
double x;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	      x=x+double(1/double(i));
     printf("%.10lf",x);
    return 0;
}