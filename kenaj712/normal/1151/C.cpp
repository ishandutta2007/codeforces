#include<bits/stdc++.h>
using namespace std;
long long odwr=500000004;
const int mod=1e9+7;
long long f(long long a)
{
    if(a==1)
        return 1;
    if(a==0)
        return 0;
    long long licz[2];
    licz[0]=0;
    licz[1]=0;
    int pom=1;
    long long last;
    for(long long x=1;2*x-1<=a;x*=2)
    {
        pom=(pom+1)%2;
        last=2*x-1;
        licz[pom]+=x;
    }
    pom=(pom+1)%2;
    licz[pom]+=(a-last);
    long long suma=0,xd;
    xd=licz[0]*2;
    xd%=mod;
    licz[0]%=mod;
    xd*=licz[0];
    xd%=mod;
    xd*=odwr;
    xd%=mod;
    suma+=xd;
    xd=2+licz[1]*2;
    xd%=mod;
    licz[1]%=mod;
    xd*=licz[1];
    xd%=mod;
    xd*=odwr;
    xd%=mod;
    suma+=xd;
    return suma%mod;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b;
    cin>>a>>b;
    cout<<(f(b)-f(a-1)+mod)%mod;
	return 0;
}