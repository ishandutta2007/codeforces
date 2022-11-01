#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m;
char s[N][N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        if(m&1)
        {
            printf("YES\n");
            for(int i=1;i<=m+1;i++)
                printf(i==m+1?"%d\n":"%d ",(i&1)?1:2);
            continue;
        }
        bool flag=false;
        for(int i=1;i<=n&&!flag;i++)
            for(int j=i+1;j<=n&&!flag;j++)
            if(s[i][j]==s[j][i])
        {
            printf("YES\n");
            flag=true;
            for(int k=1;k<=m+1;k++)
                printf(k==m+1?"%d\n":"%d ",(k&1)?i:j);
            break;
        }
        if(flag) continue;
        if(n==2)
            printf("NO\n");
        else
        {
            printf("YES\n");
            int a[4];
            a[1]=1;a[2]=2;a[3]=3;
            while(true)
            {
                if(s[a[1]][a[2]]=='a'&&s[a[2]][a[3]]=='a') break;
                if(!next_permutation(a+1,a+1+3)) break;
            }
            if(s[a[3]][a[1]]==1)
            {
                for(int i=1;i<=m+1;i++)
                    printf(i==m+1?"%d\n":"%d ",a[i%3+1]);
            }
            else
            {
                if(m==2)
                    printf("%d %d %d\n",a[1],a[2],a[3]);
                else if(m%4==0)
                {
                    m/=4;
                    printf("%d",a[2]);
                    for(int i=1;i<=m;i++)
                        printf(" %d %d %d %d",a[3],a[2],a[1],a[2]);
                    printf("\n");
                }
                else if(m%3==0)
                {
                    m/=3;
                    printf("%d",a[2]);
                    for(int i=1;i<=m;i++)
                        printf(" %d %d %d",a[3],a[1],a[2]);
                    printf("\n");
                }
                else if(m/2%3==2)
                {
                    printf("%d",a[2]);
                    for(int i=1;i<=m/2/3;i++)
                        printf(" %d %d %d",a[3],a[1],a[2]);
                    printf(" %d %d %d %d",a[3],a[2],a[1],a[2]);
                    for(int i=1;i<=m/2/3;i++)
                        printf(" %d %d %d",a[3],a[1],a[2]);
                    printf("\n");
                }
                else if(m/2%3==1)
                {
                    printf("%d",a[2]);
                    printf(" %d %d %d %d",a[3],a[2],a[1],a[2]);
                    for(int i=1;i<=(m-8)/3;i++)
                        printf(" %d %d %d",a[3],a[1],a[2]);
                    printf(" %d %d %d %d",a[3],a[2],a[1],a[2]);
                    printf("\n");

                }
            }
        }
    }
}