#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char c[10][205];
int a[4],i,j,ans,ansi;
int main()
{
	//freopen("250_a.in","r",stdin);
	//freopen("250_a.out","w",stdout);
	for(i=0;i<4;i++)
	{
		gets(c[i]);
		a[i]=strlen(c[i])-2;
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)if(j!=i&&a[i]*2>a[j])break;
		if(j==4)
		{
			ans++;
			ansi=i;
		}
		else
		{
			for(j=0;j<4;j++)if(j!=i&&a[j]*2>a[i])break;
			if(j==4)
	    	{
	    		ans++;
	    		ansi=i;
    		}
		}
	}
	if(ans==1)putchar(ansi+'A');
	else putchar('C');
	return 0;
}