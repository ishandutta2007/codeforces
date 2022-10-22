#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll p[2009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=1;
    for(int i=1;i<2000;i++)p[i]=(p[i-1]*i)%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2){cout<<0<<endl;continue;}
        ll r=p[n/2];
        r=(r*r)%mod;
        cout<<r<<endl;
    }
    return 0;
}