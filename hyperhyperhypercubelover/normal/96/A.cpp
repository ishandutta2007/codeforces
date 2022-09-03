#include<cstdio>

char s[1000];

int main()
{
	int i,n,r=0;
	scanf("%s",s);
	for(i=6;s[i];i++)if(s[i]==s[i-1]&&s[i-1]==s[i-2]&&s[i-2]==s[i-3]&&s[i-3]==s[i-4]&&s[i-4]==s[i-5]&&s[i-5]==s[i-6])
	{
		puts("YES");
		return 0;
	}
	puts("NO");
}