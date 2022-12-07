#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=1)
            {
                int check=0;
                for(int x=0;x<n;x++)
                {
                    for(int y=0;y<n;y++)
                    {
                        if(a[i][y]+a[x][j]==a[i][j])
                        {
                            check=1;
                        }
                    }
                }
                if(check==0)
                {
                    flag=1;
                }
            }
        }
    }
    if(flag==1)
        printf("No");
    else
        printf("Yes");
}