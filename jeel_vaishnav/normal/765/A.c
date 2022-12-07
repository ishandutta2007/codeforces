#include<stdio.h>
#include<string.h>
int main()
{
int n;
scanf("%d",&n);
char home[4];
scanf("%s",home);
char route[9];
for(int i=0;i<n;i++)
{
scanf("%s",route);
}
if(n%2==0)
printf("home");
else
printf("contest");
}