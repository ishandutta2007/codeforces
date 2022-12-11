# include <iostream>
# include <cstdio>
using namespace std;
const int maxn = 1e5+30;
int a[maxn];
int main()
{
    int n, x, imaxx=-1e9,imax=-1e9, ans=1;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        if(x > imaxx) imax=imaxx, imaxx = x, a[x]=-1;
        else if(x > imax) ++a[imaxx], imax = x;
    }
    for(int i=1; i<=n; ++i)
        if(a[i] > a[ans])
            ans = i;
    printf("%d\n",ans);
    return 0;
}