#include <bits/stdc++.h>
#define int long long
using namespace std;


int a[100100];

main()
{
    int n,k,l,r,b,q;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1, a+n+1);
    cout<<a[(n-1)/2+1]<<"\n";
    return 0;
}