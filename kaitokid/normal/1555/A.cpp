#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n<6){cout<<15<<endl;continue;}
        if((n%2))n++;
        cout<< 2*n+(n/2)<<endl;
         }
    return 0;
}