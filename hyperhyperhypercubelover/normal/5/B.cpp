#include<cstdio>
#include<cstring>
#include<algorithm>

char a[1111][1111];

int main()
{
	int i,j,n,m=0,t,flag=0;
    for(n=0;fgets(a[n],1111,stdin);n++)m=std::max(m,(int)(strlen(a[n])-1));
    for(i=0;i<m+2;i++)putchar('*');
    puts("");
    for(i=0;i<n;i++)
	{
		putchar('*');
		t=strlen(a[i])-1;
		for(j=0;j<(m-t+flag)/2;j++)putchar(' ');
		for(j=0;j<t;j++)putchar(a[i][j]);
		for(j=(m-t+flag)/2;j<m-t;j++)putchar(' ');
		putchar('*');
		puts("");
		flag^=t&&(m-t)%2;
	}
    for(i=0;i<m+2;i++)putchar('*');
    puts("");
}