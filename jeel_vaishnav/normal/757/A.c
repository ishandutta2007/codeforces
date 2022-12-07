#include<stdio.h>
#include<string.h>
int main()
{
char s[100001];
scanf("%s",s);
int len=strlen(s),freq[26]={0},freq_1=0;
for(int i=0;i<len;i++)
{
	if(s[i]>=97&&s[i]<=122)
	freq[s[i]-'a']++;
	if(s[i]=='B')
	freq_1++;
}
int min=freq_1;
if(freq[0]/2<min)
min=freq[0]/2;
if(freq[1]<min)
min=freq[1];
if(freq[20]/2<min)
min=freq[20]/2;
if(freq[11]<min)
min=freq[11];
if(freq[18]<min)
min=freq[18];
if(freq[17]<min)
min=freq[17];
printf("%d",min);
}