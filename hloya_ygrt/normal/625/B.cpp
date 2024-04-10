#include<stdio.h>
#include<string.h>
int main()
{
    char a[100005],b[40];
    int j,k,l,flag,len=0;
    long long count=0;
    scanf("%s",a);
    scanf("%s",b);
    j=0;
    for(int i=0;i<strlen(a);i++)
    {
        //printf("i=%d\n",i);
        len=0;
        if(a[i]==b[0])
        {
            flag=0;
            for(k=i,l=0;k<strlen(a)&&l<strlen(b);k++,l++)
            {
                if(a[k]==b[l])
                    len++;
            }
            if(len==strlen(b))
            {
                count++;
                i=i+len-1;
            }

        }
    }
    printf("%I64d\n",count);
    return 0;
}