#include<cstdio>
#include<cstring>

char str[1000000];

int main()
{
	int i,n;
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<n;i++)if(str[i]!=str[n-i-1]||(str[i]!='A'&&str[i]!='H'&&str[i]!='I'&&str[i]!='M'&&str[i]!='O'&&str[i]!='T'&&str[i]!='U'&&str[i]!='V'&&str[i]!='W'&&str[i]!='X'&&str[i]!='Y'))break;
	if(i==n)puts("YES");
	else puts("NO");
}