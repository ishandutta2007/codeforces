#include <cstdio>
#include <cstdlib>

int main()
{
    int n,k,a[105];
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (abs(a[i]-a[j])>k)
            {
                printf("NO");
                return 0;
            }
    printf("YES\n");
    for (int i=0;i<n;i++)
    {
        int c=0;
        for (int j=0;j<a[i];j++)
        {
            c=c%k+1;
            printf("%d ",c);
        }
        printf("\n");
    }
        
    return 0;
}