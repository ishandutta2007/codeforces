#include <bits/stdc++.h>
#define int long long

using namespace std;

main()
{
    int a[100100];
    int n;
    int s=0;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i], s+=a[i];
    sort(a+1, a+n+1);
    int q=0;
    while (2*s<9*n)
    {
        q++;
        s+=(5-a[q]);
    }
    cout<<q<<"\n";
    return 0;
}