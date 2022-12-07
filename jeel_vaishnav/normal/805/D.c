#include<stdio.h>
#include<string.h>
int mod=1000000007;
int main()
{
char string[1000001];
scanf("%s",string);
int len=strlen(string);
int i=len-1;
long ans=0,a,b=0;
while(i>=0)
{
       if(string[i]=='b')
           b=(b+1)%mod;
       if(string[i]=='a')
           {
           ans=(ans%mod+b%mod)%mod;
     b=(b%mod*2)%mod;
       }
       i--;
}
    printf("%ld",ans);
return 0;
}