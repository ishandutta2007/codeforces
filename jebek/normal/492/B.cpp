#include <iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int n,l,a[2000],ans;
long double b;

int main()
{
    cin>>n>>l;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ans=max(a[0]*2,(l-a[n-1])*2);
    for(int i=0;i<n-1;i++)
        ans=max(ans,a[i+1]-a[i]);
    b=ans;
    b/=2.0;
    cout<<fixed<<setprecision(9)<<b<<endl;
}