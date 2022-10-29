#include <iostream>
#include<math.h>
using namespace std;
int prime(long n)
{
    for(long i=2;i<=sqrt(n);++i)
    {
        if(n%i==0) {return 0;}
    }
    return 1;
}
int main()
{
    long n,i,c=0,m;
    cin>>n;
    if(prime(n)) c=1;
    else if(n%2==0) c=2;
    else if(prime(n-2)) c=2;
    else c=3;  
    cout<<c;
    return 0;
}