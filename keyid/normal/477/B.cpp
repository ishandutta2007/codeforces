#include <cstdio>

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",((n*3-1)*2+1)*k);
    for (int i=0;i<n;i++) 
    {
        int st=i*6+1;
        printf("%d %d %d %d\n",st*k,(st+2)*k,(st+3)*k,(st+4)*k);
    }
    return 0;
}