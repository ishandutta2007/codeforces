#include<cstdio>
#include<cstring>

char s[111];

int main()
{
	int i,j,k,n;
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++)if(s[i]=='0'||s[i]=='8')
	{
		puts("YES");
		putchar(s[i]);
		return 0;
	}
	for(i=0;i<n;i++)for(j=i+1;j<n;j++)if(((s[i]-'0')*10+s[j]-'0')%8==0)
	{
		puts("YES");
		putchar(s[i]);
		putchar(s[j]);
		return 0;
	}
	for(i=0;i<n;i++)for(j=i+1;j<n;j++)for(k=j+1;k<n;k++)if(((s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0')%8==0)
	{
		puts("YES");
		putchar(s[i]);
		putchar(s[j]);
		putchar(s[k]);
		return 0;
	}
	puts("NO");
}