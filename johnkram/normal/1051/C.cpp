#include<bits/stdc++.h>
using namespace std;
int n,x,y,i,j,a[105],s[105],b[105];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
	}
	for(i=1,j=0;i<=100;i++)if(s[i]==1)
	{
		x++;
		b[i]=j;
		j=!j;
	}
	else if(s[i]>2)y=i;
	if(!(x&1))
	{
		puts("YES");
		for(i=1;i<=n;i++)if(b[a[i]])putchar('A');
		else putchar('B');
		return 0;
	}
	if(!y)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=1;i<=n;i++)if(a[i]==y)
	{
		putchar('B');
		y=0;
	}
	else if(!b[a[i]])putchar('A');
	else putchar('B');
	return 0;
}