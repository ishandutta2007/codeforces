#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200005;
long long a[maxn];
int main()
{
    int i,n;
    long long ans;
    cin>>n;
    for (i=0;i<n*2;i++)
        cin>>a[i];
    sort(a,a+2*n);
    ans=(a[n-1]-a[0])*(a[2*n-1]-a[n]);
    for (i=0;i<n;i++)
        ans=min(ans,(a[2*n-1]-a[0])*(a[i+n-1]-a[i]));
    cout<<ans;
    return 0;
}