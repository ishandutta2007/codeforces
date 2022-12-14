#include <stdio.h>
int x[30][30],a,b;
int y[30];
void swap(int s, int t)
{
    for(int i=1;i<=a;i++) y[i] = x[i][s];
    for(int i=1;i<=a;i++) x[i][s] = x[i][t];
    for(int i=1;i<=a;i++) x[i][t] = y[i];
}
int main()
{
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
    for(int i=1;i<=b;i++)
    {
        for(int j=i;j<=b;j++)
        {
            swap(i,j);
            for(int k=1;k<=a;k++)
            {
                int count=0;
                for(int l=1;l<=b;l++)
                {
                    if(x[k][l]!=l) count++;
                }
                if(count>2) goto u;
            }
            printf("YES");
            return 0;
            u:;
            swap(i,j);
        }
    }
    printf("NO");
}