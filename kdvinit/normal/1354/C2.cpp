#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    std::cout << std::setprecision(15); std::cout << std::fixed;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        double pie= 3.141592653589793238,l=0,theta,alpha,ans=0.000000000000,den;
        m=n/2;
        theta=pie/n;
        alpha=m*theta;
        for(int i=1;i<=m;i++)
        {
            l+=cos(i*theta);
        }
        l=2*l+1.000000000000;
        den=sqrt(2*(1-sin(alpha)));
        ans=(l*cos(alpha))/den;
        cout<<ans<<endl;
    }
    return 0;
}