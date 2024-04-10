#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int k,r;
    cin>>k;
    r=100-k;
    int u=__gcd(k,r);
    k/=u;
    r/=u;
    cout<<k+r<<endl;
}
    return 0;
}