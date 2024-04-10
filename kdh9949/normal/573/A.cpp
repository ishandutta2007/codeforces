#include<stdio.h>

int a[100010],n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<n;i++)
    {
        for(;a[i]%2==0;)a[i]/=2;
        for(;a[i]%3==0;)a[i]/=3;
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1]){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
}