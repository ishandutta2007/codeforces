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

    int a[n+1],sum=0;
    for(int i=1;i<=n;i++) { cin>>a[i]; sum+=a[i]; }

    int ans=n-1;
    for(int i=0;i<=n;i++)
    {

        int val=0;
        for(int j=1;j<=i;j++) val+=a[j];

        int temp=0,flag=1;
        for(int j=i+1;j<=n;j++)
        {
            if(temp<val) temp+=a[j];
            else if (temp==val) temp=a[j];
            else
            {
                flag=0;
                break;
            }
        }

        if(flag==0 || temp!= val) continue;

        int cnt=(sum/val);
        cnt=n-cnt;
        cout<<cnt<<endl;
        return;
    }

    cout<<n-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}