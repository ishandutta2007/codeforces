#include <bits/stdc++.h>
#define int long long
using namespace std;

long long a[100100];


main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,d,b;
    cin>>n>>d>>b;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    long long num,q,s;
    s=0;
    num=0;
    while (s<(((n+1)/2)*b))
    {
        num++;
        s+=a[num];
    }
    q=a[num]-s+(((n+1)/2)*b);
    //cout<<num<<" "<<q<<"\n";

    long long p[100100];
    memset(p,0,sizeof(p));
    for (int i=1; i<num; i++)
        p[(i+d)/(d+1)]+=a[i];
    p[(num+d)/(d+1)]+=q;
    for (int i=num+1; i<=n; i++)
        p[(d*(n+1)+i)/(d+1)]+=a[i];
    p[(d*(n+1)+num)/(d+1)]+=(a[num]-q);

    long long badleft=0;
    long long left=0;
    for (int i=1; i<=((n+1)/2); i++)
    {
        left+=p[i];
        if (left<b)
            badleft++;
        else
            left-=b;
    }
    long long badright=0;
    long long right=0;
    for (int i=n; i>((n+1)/2); i--)
    {
        right+=p[i];
        if (right<b)
            badright++;
        else
            right-=b;
    }
    cout<<max(badright,badleft)<<"\n";
    return 0;
}
/*
5 1 1
1 0 0 0 4
*/