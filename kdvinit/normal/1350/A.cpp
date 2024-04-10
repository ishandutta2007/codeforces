/*
KDVINIT

*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int k,n;
        cin>>n>>k;
        if(n%2==0) {cout<<n+2*k<<endl; continue;}
        else
        {
            int i;
            for(i=3;i*i<=n;i+=2)
            {
                if(n%i==0) break;
            }
            if(i*i>n) cout<<2*n+2*(k-1)<<endl;
            else cout<<n+i+2*(k-1)<<endl;
        }
    }
    return 0;
}