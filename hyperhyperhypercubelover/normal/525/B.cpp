#include<cstdio>
#include<cstring>
#include<algorithm>

char s[222222];
int a[222222];

int main()
{
    int i,j,n,m;
	scanf("%s%d",s,&m);
	n=strlen(s);
	for(i=0;i<m;i++)
	{
        scanf("%d",&j);
        a[std::min(j-1,n-j)]++;
        a[std::max(j,n-j+1)]--;
	}
    for(i=0;i<n;i++)
	{
		if(i)a[i]+=a[i-1];
		if(a[i]%2)putchar(s[n-i-1]);
		else putchar(s[i]);
	}
}