#include <bits/stdc++.h>

using namespace std;
long long a[100009], n;
int main()
{
cin>>n;

    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    cout<<a[2]-a[1]<<' ';
    cout<<a[n]-a[1]<<'\n';

    for(long long i=2;i<n;i++)
    {
        cout<<min(a[i]-a[i-1], a[i+1]-a[i])<<' ';
        cout<<max(a[i]-a[1], a[n]-a[i])<<'\n';
    }
    cout<<a[n]-a[n-1]<<' ';
    cout<<a[n]-a[1]<<'\n';

    return 0;
}