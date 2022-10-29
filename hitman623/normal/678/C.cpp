#include <iostream>

using namespace std;
long long hcf(long long a,long long b)
{
    if(a==0) return(b);
    if(a>b) return(hcf(a%b,b));
    else return hcf(b%a,a);
}

int main()
{
    long long n,a,b,p,q,gc;
    cin>>n>>a>>b>>p>>q;
    gc=(a*b)/hcf(a,b);
    if(p>q)
    {
        cout<<(n/a)*p+(n/b)*q-(n/gc)*q;
    }
    else
        cout<<(n/a)*p+(n/b)*q-(n/gc)*p;
    return 0;
}