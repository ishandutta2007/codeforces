#include<bits/stdc++.h>
using namespace std;
int a[20]={0,31,28,31,30,31,30,31,31,30,31,30},b[7],i,j,m,n;
string x,y;
void work(string a,int &b)
{
	if(a[0]=='m')b=1;
	else if(a[0]=='w')b=3;
	else if(a[0]=='f')b=5;
	else if(a[1]=='h')b=4;
	else if(a[1]=='a')b=6;
	else if(a[0]=='t')b=2;
	else b=7;
}
int main()
{
	cin>>x>>y;
	for(i=1;i<=11;i++)b[a[i]%7]=1;
	work(x,m);
	work(y,n);
	if(b[(n-m+7)%7])puts("YES");
	else puts("NO");
	return 0;
}