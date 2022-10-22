#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
ll t;
cin>>t;
while(t--)
{
    ll r,d,b;
    cin>>r>>b>>d;
    if(r>b)swap(r,b);
    r+=r*d;
    if(r<b)cout<<"NO\n";
    else cout<<"YES\n";
}
    return 0;
}