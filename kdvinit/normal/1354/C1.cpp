/*

std::cout << std::setprecision(15); std::cout << std::fixed;
*****The Above line was used to set the precision
***** Dont forget to use the library #include <bits/stdc++.h>

*/


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
        int n;
        cin>>n;
        double x= 3.141592653589793238/2,ans=0.000000000000;
        n/=2;
        x/=n;
        for(int i=1;i<n;i++)
        {
            ans+=sin(i*x);
        }
        ans=2*ans+1.000000000000;
        cout<<ans<<endl;
    }
    return 0;
}