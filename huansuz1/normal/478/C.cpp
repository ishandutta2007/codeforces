#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

long long a[4],ans;

int main()
{
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);

    if (a[2]-a[0]<=1) {
        cout<<(a[0]+a[1]+a[2])/3; 
        return 0; 
    }
    if ((a[0]+a[1])*2<=a[2]) {
        cout<<a[0]+a[1];
        return   0;
    }

    if (a[1]+a[0]>=(a[1]+a[2]+a[0])/3) {
        cout<<(a[1]+a[2]+a[0])/3;
        return 0;
    }
    ans=a[0];
    a[1]-=a[0];
    a[2]-=a[0];
    if ((a[1]+a[2])/3<=a[1]) ans+=(a[1]+a[2])/3; else 
        ans+=a[1];

    cout<<ans;
    return 0;
}