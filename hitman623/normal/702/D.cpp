#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long d,k,a,v,b,t,ti=0;
    cin>>d>>k>>a>>b>>t;
    if(a<b)
    {    d-=k;
         if(d<=0) {ti+=(d+k)*a;goto p;}
         ti+=a*k;
         if(a*k+t<b*k)
            ti+=(d/k)*(a*k+t);
            else {ti+=(d*b);goto p;}
         d%=k;
         if(a*d+t<b*d)
            ti+=a*d+t;
            else ti+=b*d;
    }
    else
    {
        ti+=d*b;
    }
    p:
    cout<<ti;
    return 0;
}