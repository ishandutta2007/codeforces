#include <iostream>

using namespace std;

long long n,k,a,MIN=100000000000000,p,x[100100];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        x[i%k]+=a;
    }
    for(int i=1;i<k;i++)
    {
        if(x[i]<MIN)
        {
            p=i;
            MIN=x[i];
        }
    }
    if(x[0]<MIN)
        p=k;
    cout<<p<<endl;
}