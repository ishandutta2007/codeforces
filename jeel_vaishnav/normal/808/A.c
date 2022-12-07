#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
int num;
scanf("%d",&num);
int temp=num,check=1,ans;
    temp/=10;
while(temp!=0)
{
check*=10;
temp/=10;
}
if(num%check==0)
ans=check;
else
    {
    ans=((num/check)+1)*check-num;
}
    printf("%d",ans);    
return 0;
}