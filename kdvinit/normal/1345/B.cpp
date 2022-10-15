#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,ans=0;
        cin>>n;
        while(n>1)
        {
            long long int x=(-1+sqrt(1+24*n))/6;
            n-=((3*x+1)*x)/2;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}