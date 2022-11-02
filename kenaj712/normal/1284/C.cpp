#include<bits/stdc++.h>
using namespace std;
long long silnia[1000005];
int mod;
void pre()
{
    silnia[1]=1;
    silnia[0]=1;
    for(int x=2;x<=5e5;x++)
        silnia[x]=(silnia[x-1]*x)%mod;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a;
    cin>>a>>mod;
    pre();
    long long out=0;
    for(long long x=a;x>=1;x--)
    {
        long long pom=(x*x)%mod;
        pom=(pom*silnia[a-x+1])%mod;
        pom=(pom*silnia[x-1])%mod;
        out+=pom;
    }
    cout<<out%mod;
    return 0;
}