#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

inline int solve(LL x)
{
    int ans=0;
    for (int i=0;i<=62;i++)
    {
        LL t=(1ULL<<(i+1))-1;
        for (int j=0;j<i;j++)
            if (t-(1LL<<j)<=x)
                ans++;
    }
    return ans;
}

int main()
{
    LL a,b;
    scanf("%I64d%I64d",&a,&b);
    printf("%d\n",solve(b)-solve(a-1));
    return 0;
}