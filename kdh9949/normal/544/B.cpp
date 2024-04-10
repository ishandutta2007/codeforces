#include<stdio.h>
int n,s,i,j,k;
int main()
{
    scanf("%d%d",&n,&s);
    if(s>(n*n+1)/2)
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i%2==j%2 && k<s) printf("L"),k++;
            else printf("S");
        }
        puts("");
    }
}