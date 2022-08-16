#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans1(ll b, ll d, ll s)
{
    ll cnt = max(b,max(d,s));
    if(s == cnt)
    {
        return cnt - b + cnt-d;
    }
    if(d == cnt)
    {
        return cnt- b + cnt-s-1;
    }
    return 2*cnt - d - s - 2;
}
int main()
{
    ll b,d,s;
    cin>>b>>d>>s;
    ll b1 = d,d1=s,s1=b;
    ll b2 = s,d2=b,s2=d;
    cout<<min(ans1(b,d,s),min(ans1(b1,d1,s1),ans1(b2,d2,s2)));
}