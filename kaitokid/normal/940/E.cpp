#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
multiset<ll> v;
ll mn[100009],a[100009],dp[100009],n,c,x,sum;
ll go(ll i)
{
if(i>n-1)return 0;
if(dp[i]>0)return dp[i];
return dp[i]=max(go(i+1),mn[i]+go(i+c));
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>c;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    if(n<c){cout<<sum;return 0;}
    for(int i=0;i<c;i++)v.insert(a[i]);
    mn[c-1]=(*v.begin());
    for(int i=c;i<n;i++)
    {
        v.erase(v.lower_bound(a[i-c]));
        v.insert(a[i]);
        mn[i]=(*v.begin());
    }
    cout<<sum-go(c-1);

    return 0;
}