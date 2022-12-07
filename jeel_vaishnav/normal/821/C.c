#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1],j=0,k=1,sorted_i=-1,ans=0;
    for(int i=0;i<2*n;i++)
    {
        char s[7];
        int b;
        scanf("%s",s);
        if(s[0]=='a')
        {
            scanf("%d",&b);
            a[j++]=b;
        }
        if(s[0]=='r')
        {
            if(j-1==sorted_i)
            {
                j--;
                sorted_i--;
            }
            else if(a[j-1]==k)
            {
                j--;
            }
            else
            {
                ans++;
                j--;
                sorted_i=j-1;
            }
            k++;
        }
    }
    printf("%d",ans);
}