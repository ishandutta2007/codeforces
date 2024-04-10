#include <bits/stdc++.h>

using namespace std;

map <long long, long long> mapa;
int main()
{
    long long n,a,b,p,q,br,x,y,z;
    cin>>n>>a>>b>>p>>q;
    if(p>q){swap(a,b);swap(p,q);}
    x=n/b;
    y=n/a;
    y-=n/(a*b/__gcd(a,b));
    br=x*q+y*p;
    cout<<br;
    return 0;
}