#include<cstdio>
#include<algorithm>

char s[4];
char t[4];

int main()
{
	scanf("%s%s",s,t);
	printf("%d\n",std::max(std::abs(s[0]-t[0]),std::abs(s[1]-t[1])));
    while(s[0]!=t[0]||s[1]!=t[1])
	{
		if(s[0]<t[0])
		{
			putchar('R');
			s[0]++;
		}
		if(s[0]>t[0])
		{
			putchar('L');
			s[0]--;
		}
		if(s[1]<t[1])
		{
			putchar('U');
			s[1]++;
		}
		if(s[1]>t[1])
		{
			putchar('D');
			s[1]--;
		}
		puts("");
	}
	return 0;
}