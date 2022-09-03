#include<cstdio>
#include<cstring>

char a[100];
char b[100];

int main()
{
int x=0,y=0;
int i,n;
scanf("%s%s",a,b);
n=strlen(a);
for(i=0;i<n;i+=2)
{
if(a[i]=='8'&&b[i]=='[')x++;
if(a[i]=='['&&b[i]=='(')x++;
if(a[i]=='('&&b[i]=='8')x++;
if(a[i]=='['&&b[i]=='8')y++;
if(a[i]=='('&&b[i]=='[')y++;
if(a[i]=='8'&&b[i]=='(')y++;
}
if(x>y)printf("TEAM 1 WINS");
if(x<y)printf("TEAM 2 WINS");
if(x==y)printf("TIE");
}