#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    cout<<fixed<<setprecision(13);
    long double h,n,a,i;
    cin>>n>>h;
    a=h/(2*n);
    for(i=1;i<n;++i)
    cout<<sqrt(2*a*i*h)<<" ";
    return 0;
}