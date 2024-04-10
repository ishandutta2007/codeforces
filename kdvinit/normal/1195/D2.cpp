/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353 ;

int len(int x)
{
    int ans=0;
    while(x!=0)
    {
        x/=10;
        ans++;
    }
    return ans;
}

int insert_odd(int ln,int x)
{
    int cnt=1,ans=0;
    while(x!=0)
    {
        int y=x%10;
        x/=10;
        ans+=(y*cnt);
        ans%=mod;
        cnt*=10;
        cnt%=mod;
        if(ln!=0) { cnt*=10; ln--; }
    }
    return ans;
}

int insert_even(int ln,int x)
{
    int cnt=1,ans=0;
    while(x!=0)
    {
        if(ln!=0) { cnt*=10; ln--; }
        int y=x%10;
        x/=10;
        ans+=(y*cnt);
        ans%=mod;
        cnt*=10;
        cnt%=mod;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int freq[11]={0},ans=0;

    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        x=len(x);
        freq[x]++;
    }

    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x=a[j];
            int y=(freq[i]*insert_odd(i,x))%mod;
            ans+=y;
            ans%=mod;
            y=(freq[i]*insert_even(i,x))%mod;
            ans+=y;
            ans%=mod;
        }
    }

    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}