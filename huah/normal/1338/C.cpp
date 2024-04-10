#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Find(ll s,ll k,ll b)
{
    if(b==0) return s;
    if(k/b==0) return Find(s,k%b,b/4);
    if(k/b==1) return Find(s+2*b,k%b,b/4);
    if(k/b==2) return Find(s+3*b,k%b,b/4);
    return Find(s+b,k%b,b/4);
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll l=1,k=(n-1)/3+1;
        while(k>l)
        {
            k-=l;
            l*=4;
        }
        if(n%3==1) printf("%lld\n",l+k-1);
        else if(n%3==2)
            printf("%lld\n",Find(l+l,k-1,l/4));
        else
            printf("%lld\n",(l+k-1)^Find(l+l,k-1,l/4));
    }
}