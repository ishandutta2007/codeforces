#include<cstdio>
#include<cstring>

char str[1000];

int main()
{
	int i,n,m;
	gets(str);
	sscanf(str,"%d",&n);
	for(i=0;i<n;i++)
	{
		gets(str);
		m=strlen(str);
		if(str[0]=='m'&&str[1]=='i'&&str[2]=='a'&&str[3]=='o'&&str[4]=='.')
		{
			if(str[m-1]=='.'&&str[m-2]=='a'&&str[m-3]=='l'&&str[m-4]=='a'&&str[m-5]=='l')
				puts("OMG>.< I don\'t know!");
			else
				puts("Rainbow\'s");
		}
		else
		{
			if(str[m-1]=='.'&&str[m-2]=='a'&&str[m-3]=='l'&&str[m-4]=='a'&&str[m-5]=='l')
				puts("Freda\'s");
			else
				puts("OMG>.< I don\'t know!");
		}
	}
}