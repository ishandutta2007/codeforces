#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

int a[MAXN*2];

int main()
{
    int n,_min=INT_MAX;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        _min=min(_min,a[i]);
        a[i+n]=a[i];
    }
    int last=0,ans=0;
    for (int i=0;i<n*2;i++)
        if (a[i]==_min)
        {
            ans=max(ans,i-last);
            last=i;
        }
    printf("%I64d",(LL)_min*n+ans-1);
    return 0;
}