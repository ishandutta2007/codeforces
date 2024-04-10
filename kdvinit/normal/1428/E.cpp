/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int val(int x,int n)
{
    int ans=0;
    int y=(x/n);
    int z=x%n;
    ans+=( (y*y)*(n-z) );
    y++;
    ans+=( (y*y)*(z) );
    return ans;
}

int diff(int x,int n)
{
    int ans=val(x,n)-val(x,n+1);
    return ans;
}

void solve()
{
    int n,k,x;
    cin>>n>>k;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    int cnt[n+1];
    for(int i=1;i<=n;i++) cnt[i]=1;

    multimap<int,int> parts;
    multimap<int, int>::iterator itr;
    for(int i=1;i<=n;i++)
    {
        parts.insert(pair<int, int>(diff(a[i],cnt[i]),i));
    }

    for(int i=n+1;i<=k;i++)
    {
        itr=parts.end(); itr--;
        x=itr->second;
        cnt[x]++;
        parts.erase(itr);
        parts.insert(pair<int, int>(diff(a[x],cnt[x]),x));
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans+=val(a[i],cnt[i]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}