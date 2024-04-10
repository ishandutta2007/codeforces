#include<cstdio>

char s[100];

int main()
{
	int i,n,r=0;
	scanf("%d%s",&n,s);
	for(i=1;i<n;i++)if(s[i]==s[i-1])r++;
	printf("%d",r);
}