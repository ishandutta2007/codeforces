/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    multiset<int> sum;
    int temp=0,ans=0;
    sum.insert(0);

    for(int i=1;i<=n;i++)
    {
        temp+=a[i];
        int x=sum.count(temp);
        if(x==0) { sum.insert(temp); continue; }
        ans++;
        sum.clear();
        sum.insert(temp);
        sum.insert(temp-a[i]);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}