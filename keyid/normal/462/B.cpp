#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


bool cmp(int x,int y)
{
    return  x>y;
}
int main()
{
    int n,k,a[26];
    long long ans=0;
    scanf("%d%d",&n,&k);
    memset(a,0,sizeof(a));
    getchar();
    for (int i=0;i<n;i++)
    {
        char x;
        scanf("%c",&x);
        a[x-'A']++;
    }
    sort(a,a+26,cmp);
    for (int i=0;i<26;i++)
    {
        int m=min(k,a[i]);
        ans+=(long long)m*m;
        if ((k-=a[i])<=0) break;
    }
    printf("%I64d",ans);
    return 0;
}