#include <stdio.h>

long long int min(long long int a, long long int b)
{
    return a<b?a:b;
}
long long int x[10010],y[10010], check[10][10010];
int main()
{
    int a;
    long long int b,ans;
    scanf("%d%I64d",&a,&b);
    for(int i=1;i<=a;i++) scanf("%I64d",&x[i]);
    for(int i=1;i<=a;i++) scanf("%I64d",&y[i]);
    for(int i=1;i<=a;i++)
    {
        check[(i%2)][0] = check[(i+1)%2][0] + x[i];
        for(int j=1;j<i;j++) check[i%2][j] = min( check[(i+1)%2][j-1]+y[i],check[(i+1)%2][j] + x[i] + j*b);
        check[(i%2)][i] = check[(i+1)%2][i-1] + y[i];
    }
    ans = check[a%2][0];
    for(int i=1;i<=a;i++) ans = min(ans,check[a%2][i]);
    printf("%I64d",ans);
}