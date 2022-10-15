/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int freq[61]={0};
    for(int i=1;i<=n;i++)
    {
        int x=a[i],cnt=0;
        while(x!=0)
        {
            if(x%k>1) { cout<<"NO"<<endl; return; }
            if(x%k==1 && freq[cnt]==1) { cout<<"NO"<<endl; return; }
            if(x%k==1) freq[cnt]=1;
            x/=k;
            cnt++;
        }
    }
    cout<<"YES"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}