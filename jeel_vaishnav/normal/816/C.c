#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int min0[n],min1[m],count=0;
    if(n<=m)
    {
        for(int i=0;i<n;i++)
        {
            int min=501;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]<min)
                    min=a[i][j];
            }
            min0[i]=min;
            count+=min;
            for(int j=0;j<m;j++)
            {
                a[i][j]-=min;
            }
        }

        for(int i=0;i<m;i++)
        {
            int min=501;
            for(int j=0;j<n;j++)
            {
                if(a[j][i]<min)
                    min=a[j][i];
            }
            min1[i]=min;
            count+=min;
            for(int j=0;j<n;j++)
            {
                a[j][i]-=min;
            }
        }
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            int min=501;
            for(int j=0;j<n;j++)
            {
                if(a[j][i]<min)
                    min=a[j][i];
            }
            min1[i]=min;
            count+=min;
            for(int j=0;j<n;j++)
            {
                a[j][i]-=min;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int min=501;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]<min)
                    min=a[i][j];
            }
            min0[i]=min;
            count+=min;
            for(int j=0;j<m;j++)
            {
                a[i][j]-=min;
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!=0)
            {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d\n",count);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=min0[i];j++)
        printf("row %d\n",i+1);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=min1[i];j++)
        printf("col %d\n",i+1);
    }
}