#include <bits\stdc++.h>
using namespace std;
    const int maxn=2e5;
    const int eps=1e-8;
    const int inf=2e9;

    #define mp make_pair
    #define f first
    #define sec second
    #define pb push_back

    long long a[maxn];

int main()
{
    long long n;   ///freopen("input.txt","r",stdin);
    scanf("%I64d",&n);

    long long mn=0,lst;
    for (int i=0;i<n;i++)
    {
        scanf("%I64d",a+i);
        if (a[mn]>a[i])
            mn=i;
    }
    lst=mn;
    long long lng=0;

    for (int i=lst+1;i<n;i++)
    {
        if (a[i]==a[mn])
            {
                lng=max(lng,i-lst-1);
                lst=i;
            }
    }

    lng=max(lng,n-lst+mn-1);

    long long ans=lng+(long long)(a[mn]*n);
    cout<<ans;
    return 0;
}