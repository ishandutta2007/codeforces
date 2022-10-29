#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long long n,a,c=0,d=1,i;
    cin>>n;
    a=n;
    while(a>0)
    {
        a/=10;
        c++;
    }
    c--;
    for(i=0;i<c;++i)
    d*=10;
    cout<<d-n%d;
    return 0;
}