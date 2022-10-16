#include <iostream>

using namespace std;
long long n, m, a, s;
int main()
{
cin>>n;

for(long long i=1;i<=n;i++)
{
    cin>>a;
    if(a>m)m=a;
    s+=a;
}

s-=m;
cout<<m-s+1<<'\n';

    return 0;
}