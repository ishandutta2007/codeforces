// Hydro submission #62d4a5b4b36e4a12382db99c@1658103221474
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,k2=0,k3=0,k5=0;
    cin>>a>>b;
    c=__gcd(a,b);
    d=a/c,e=b/c;
    while(d%2==0) d/=2,k2++;
    while(e%2==0) e/=2,k2++;
    while(d%3==0) d/=3,k3++;
    while(e%3==0) e/=3,k3++;
    while(d%5==0) d/=5,k5++;
    while(e%5==0) e/=5,k5++;
    printf("%d\n",d==e?k2+k3+k5:-1);
    return 0;
}