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
    ll n,m,k;
    cin>>n>>m>>k;
    ll dst= n-1+ n*(m-1);
    if(dst==k)cout<<"YES\n";
    else cout<<"NO\n";
}
    return 0;
}