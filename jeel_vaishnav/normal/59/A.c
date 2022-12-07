#include<stdio.h>
#include<string.h>
int main()
{
char s[101];
scanf("%s",s);
int len=strlen(s),freq_l=0,freq_u=0;
for(int i=0;i<len;i++)
{
if(s[i]>=65&&s[i]<=90)
freq_u++;
else
freq_l++;
}
if(freq_u>freq_l)
	{
	for(int i=0;i<len;i++)
	{
	if(s[i]>=97&&s[i]<=122)
	s[i]-=32;
	}
	}
if(freq_u<=freq_l)
	{
	for(int i=0;i<len;i++)
	{
	if(s[i]>=65&&s[i]<=90)
	s[i]+=32;
	}
	}
printf("%s",s);
}