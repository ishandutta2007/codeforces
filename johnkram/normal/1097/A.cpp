#include<bits/stdc++.h>
using namespace std;
char c[10],d[10][10];
int n=5,i;
int main()
{
	cin>>c;
	for(i=0;i<n;i++)cin>>d[i];
	for(i=0;i<n;i++)if(d[i][0]==c[0]||d[i][1]==c[1])
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}