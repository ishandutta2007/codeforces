#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

int main()
{
    long long n,a[100005],i,s=0;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;++i)
        s+=a[n-1]-a[i];
    cout<<s;
    return 0;
}