#include<bits/stdc++.h>
using namespace std;
double a,x,y;
int cnt;
int main()
{
	cin>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>x>>y;
		a+=y;
	}
	printf("%.3lf",5+a/cnt);
}