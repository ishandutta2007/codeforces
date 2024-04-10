#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    ll n,m,k;
    cin>>n>>m>>k;
    if(k<n){cout<<k+1<<" "<<1;return 0;}
    k-=n;
    ll x=k/(m-1);
    ll y=k%(m-1);
    x=n-x;
    if(x%2)y=m-2-y;
    cout<<x<<" "<<y+2;
    return 0;
}