#include <bits/stdc++.h>
#define int double
using namespace std;

int a[10000];

main()
{
    long long n;
    cin>>n;
    for (long long i=1; i<=n; i++)
        cin>>a[i];
   for (long long i=1; i<=n; i++)
   for (long long j=n-1; j>=i; j--)
   if (a[j]>a[j+1]) swap(a[j],a[j+1]);
     for (long long i=1; i<=n; i++)
        cout<<" "<<a[i];
    clock_t c=clock();
    while(clock()-c<CLOCKS_PER_SEC);
    return 0;
}