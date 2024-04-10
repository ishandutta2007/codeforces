#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>

#define ll long long
using namespace std;

int main()
{
    ll a,b,k;
    ll ans=0;
    cin>>k>>a>>b;

    if (b>=0&&a<=0)
     //if (k!=1)
      ans++;
    if (a<0&&b<0)
    {
        swap(a,b);
        a*=-1;
        b*=-1;
    }

   // if (b==0&&a==0)
     //   ans--;
    if (a>0)
    ans+=(b/k)-((a-1)/k);
    else
    ans+=(b/k)-((a)/k);
    cout<<ans;
    return 0;
}