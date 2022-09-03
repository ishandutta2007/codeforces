#include<cstdio>

char s[333333];
char j[3];

int main()
{
int i,n,m,t=0;
scanf("%d%d%s",&n,&m,s+1);
for(i=1;i<n;i++)t+=s[i]=='.'&&s[i+1]=='.';
while(m--)
{
scanf("%d%s",&i,j);
t-=s[i-1]=='.'&&s[i]=='.';
t-=s[i]=='.'&&s[i+1]=='.';
s[i]=j[0];
t+=s[i-1]=='.'&&s[i]=='.';
t+=s[i]=='.'&&s[i+1]=='.';
printf("%d\n",t);
}
}