#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,d,e,f,g,h,mod;
    cin>>a>>b>>c>>d;
    mod=b;
    e=(d-c)%mod;
    e=(e+mod)%mod;
    f=a*b;
    long long mini=1e18,maks=-1e18,pom=2*1e5;
    while(pom--)
    {
        mini=min(mini,f/__gcd(e,f));
        maks=max(maks,f/__gcd(e,f));
        e+=b;
    }
    e=(-d-c)%mod;
    e=(e+mod)%mod;
    pom=2*1e5;
    while(pom--)
    {
        mini=min(mini,f/__gcd(e,f));
        maks=max(maks,f/__gcd(e,f));
        e+=b;
    }
    cout<<mini<<" " <<maks<<'\n';
	return 0;
}