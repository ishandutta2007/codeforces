#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long fast_pow(long long a,long long b)
{
    long long out=1,mnoz=a;
    while(b!=0)
    {
        if(b%2==1)
            out*=mnoz;
        mnoz=(mnoz*mnoz)%mod;
        out%=mod;
        b/=2;
    }
    return out;
}
set<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,out=1;
    cin>>a>>b;
    c=a;
    for(int x=2;x*x<=c;x++)
        while(a%x==0)
        {
            a/=x;
            s.insert(x);
        }
    if(a!=1)
        s.insert(a);
    for(auto x:s)
    {
        //cout<<x<<'\n';
        long long pom=0,dziel=x;
        while(0==0)
        {
            pom+=b/dziel;
            if(log10(dziel)+log10(x)>log10(b)+0.5)
                break;
            dziel*=x;
        }
        out*=fast_pow(x,pom);
        out%=mod;
    }
    cout<<out;
	return 0;
}