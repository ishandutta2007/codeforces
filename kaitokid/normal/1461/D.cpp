#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[100009];
map<ll,bool>mp;
void go(int l,int r)
{
   // cout<<l<<" "<<r<<endl;
    if(l>r)return;
    if(l==r){mp[a[l]]=true;return ;}
    ll sum=0,d=(a[r]+a[l])/2;
    int g=r+1;
    for(int i=l;i<=r;i++)
    {
        sum+=a[i];
        if(a[i]>d)g=min(g,i);
    }
    mp[sum]=true;
    if(g==r+1||g==l)return;
    go(l,g-1);
    go(g,r);
}
int main()
{
    ios::sync_with_stdio(0);
int t,n,m;
cin>>t;
while(t--)
{
    cin>>n>>m;
mp.clear();
for(int i=0;i<n;i++)
    cin>>a[i];
sort(a,a+n);
go(0,n-1);
ll x;
while(m--)
{
    cin>>x;
    if(mp[x])cout<<"Yes\n";
    else cout<<"No\n";
}
}
    return 0;
}