#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    long long n,a[100001],i,b[100001],j;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
        a[n]=0;
    for(j=n-1;j>=0;--j)
        b[j]=a[j]+a[j+1];
        for(i=0;i<n;++i)
            cout<<b[i]<<" ";
    return 0;
}