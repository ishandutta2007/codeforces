// Hydro submission #62d29d5275c677124c8ecc21@1657970002392
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        printf(n%2?"-1\n":"%d %d 0\n",n/2,n/2);
    }
    return 0;
}