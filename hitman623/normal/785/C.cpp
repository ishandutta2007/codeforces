#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<setprecision(30);
    long double n,m;
    cin>>n>>m;
    if(m>=n)
    cout<<n;
    else
    cout<<m+ceil((-1+sqrt(1+8*(n-m)))/2.0);
    return 0;
}