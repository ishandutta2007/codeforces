#include <stdio.h>
char x[1010][10];
int main()
{
    int a,i,j;
    scanf("%d",&a);
    for(i=1;i<=a;i++) scanf("%s",x[i]+1);
    for(i=1;i<=a;i++)
    {
        if(x[i][1]=='O'&&x[i][2]=='O')
        {
            x[i][1]=x[i][2]='+';
            break;
        }
        if(x[i][4]=='O'&&x[i][5]=='O')
        {
            x[i][4]=x[i][5]='+';
            break;
        }
    }
    if(i<=a)
    {
        printf("YES\n");
        for(i=1;i<=a;i++)
        {
            for(j=1;j<=5;j++)
            {
                printf("%c",x[i][j]);
            }
            printf("\n");
        }
    }
    else printf("NO");
}