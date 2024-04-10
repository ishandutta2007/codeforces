#include <bits/stdc++.h>

using namespace std;

double l, p, q; 

int main()
{
    cin>>l>>p>>q;
    double t=1.*l/(p+q);
    double ans=t*p;
    printf("%.8f", ans);
    return 0;
}