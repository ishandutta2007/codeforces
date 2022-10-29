#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,a,b,aa,bb,i,m;
    cin>>n;
    bb=n;
    for(a=1;a<=bb;++a)
    {
        if(n%a==0) {b=n/a;if(b-a<m){aa=a;bb=n/a;} m=b-a;}
    }
    cout<<bb<<" "<<aa;
    return 0;
}