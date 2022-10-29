#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,a[300000],i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<a[(n-1)/2];
    return 0;
}