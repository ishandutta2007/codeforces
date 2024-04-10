#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long double n,k,a[102],s=0;
    long i;
    cin>>n>>k;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    cout<<max((long double )0,2*(n*(k-0.5)-s));
    return 0;
}