#include<stdio.h>
char a[111111],b[111111],c[111111];
int n,i,j,k;
int main()
{
    scanf("%s%s",a,b);
    for(n=0;a[n];n++);
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])k++;
    }
    if(k&1)
    {
        printf("impossible\n");
    }
    else
    {
        for(i=0;j<k/2;i++)
        {
            if(a[i]!=b[i])putchar(a[i]),j++;
            else putchar(a[i]);
        }
        for(;i<n;i++)
        {
            if(a[i]!=b[i])putchar(b[i]);
            else putchar(b[i]);
        }
    }
}