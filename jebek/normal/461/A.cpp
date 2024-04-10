#include <iostream>
#include<algorithm>

using namespace std;

long long n,a[400000],ans;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++)
        ans+=a[i]*(i+2);
    ans+=a[n-1]*n;
    cout<<ans<<endl;
}