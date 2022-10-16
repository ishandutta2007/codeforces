#include <iostream>
#include <cmath>
using namespace std;

int t;

void solve(long long l, long long r)
{
    if(l==r)
    {
        cout<<l<<'\n';
        return;
    }
    int lg1=log2(l), lg2=log2(r);
    if(lg1==lg2)
    {
        long long a=1, b;
        while(l<=r && a<=r)
        {
            b=a&l;
            if(b==0 && l+a<=r)
                l=l+a;
            a=a<<1;
        }
        cout<<l<<'\n';
    }
    else
        {
            long long a=1;
            while(a<=r)
            {
                a=(a<<1)+1;
            }
        a=a>>1;
        cout<<a<<'\n';
        }



}

int main()
{
cin>>t;
    long long a, b;
for(int i=1;i<=t;i++)
{
    cin>>a>>b;
    solve(a, b);
}
        return 0;
}