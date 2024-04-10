#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define bs binary_search
#define all(a) a.begin(),a.end()
using namespace std;

int main()
{
    ll n,a[200005],i;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n/2;++i,i++)
    {
        swap(a[i],a[n-i-1]);
    }
    for(i=0;i<n;++i)
        cout<<a[i]<<" ";
    return 0;
}