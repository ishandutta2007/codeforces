#include <iostream>

using namespace std;

long long n,m,k,t,a,MIN=10000000000000;

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(i%2==0)
        {
            t++;
            MIN=min(MIN,a);
        }
    }
    if(n%2==0)
        cout<<0<<endl;
    else
    {
        t=m/t;
        cout<<min(MIN,k*t)<<endl;
    }
}