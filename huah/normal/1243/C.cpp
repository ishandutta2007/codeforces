#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    scanf("%lld",&n);
    vector<ll>v;
    for(ll i=2;i*i<=n;i++)
        if(n%i==0)
        {
            v.emplace_back(i);
            while(n%i==0)
                n/=i;
        }
    if(n>1) v.emplace_back(n);
    if(v.size()>1||v.size()==0) printf("1\n");
    else printf("%lld\n",v[0]);
}