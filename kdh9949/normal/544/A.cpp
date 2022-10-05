#include<stdio.h>
int k,i,j,v[256],cut[30],p;
char a[123];
int main()
{
    scanf("%d%s",&k,a);
    for(i=0;a[i];i++)
    {
        if(v[a[i]]==0)
        {
            cut[j++]=i;
            v[a[i]]=1;
            if(j==k){while(a[i])i++;break;}
        }
    }
    if(j<k)
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    cut[j]=i;
    for(i=0;i<j;i++)
    {
        for(p=cut[i];p<cut[i+1];p++)putchar(a[p]);
        puts("");
    }
}