#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

long long n,ans,k,a[100100];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ans=a[0]*n;
    for(int i=1;i<n;i++)
    {
        ans+=(2*i+1)*(n-i)*(a[i]-a[i-1]);
       // cout<<ans<<endl;
    }
    k=__gcd(ans,n);
    cout<<ans/k<<" "<<n/k<<endl;
}