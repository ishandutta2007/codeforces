#include<cstdio>

char s[222222];
char r[222222];
int rn;

int main()
{
int i,n;
scanf("%d%s",&n,s);
for(i=0;i<n;i++)
{
if(rn&&r[rn-1]!=s[i])rn--;
else r[rn++]=s[i];
}
printf("%d\n",rn);
}