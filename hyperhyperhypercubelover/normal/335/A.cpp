#include<cstdio>
#include<cstring>

int count[26];

char str[1001];

int main()
{
int i,j,k,n,m;
scanf("%s%d",str,&m);
n=strlen(str);
for(i=0;i<n;i++)count[str[i]-'a']++;
j=0;
for(i=0;i<26;i++)if(count[i])j++;
if(j>m)printf("-1");
else
{
j=0;
for(i=0;i<26;i++)if((count[i]+m-1)/m>j)j=(count[i]+m-1)/m;
for(i=1;i<=1000;i++)
{
k=0;
for(j=0;j<26;j++)k+=(count[j]+i-1)/i;
if(k<=m)break;
}
printf("%d\n",i);
for(j=0;j<26;j++){m-=(count[j]+i-1)/i;for(k=0;k<(count[j]+i-1)/i;k++)printf("%c",j+'a');}
for(j=0;j<m;j++)printf("z");
}
}