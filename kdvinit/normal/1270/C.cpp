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

    int xxor=a[1];
    for(int i=2;i<=n;i++) xxor=xxor^a[i];
    xxor*=2;

    vector<int> ans;
    if(xxor==sum) { cout<<0<<endl<<endl; return; }

    if(sum>xxor || sum%2==1)
    {
        int x=0;
        if(sum%2==1)
        {
            x=1;
            sum+=1;
            xxor/=2;
            xxor^=1;
            xxor*=2;
        }

        int y=1,temp=sum;
        while(temp!=0)
        {
            y*=2;
            temp/=2;
        }

        if(sum>xxor)
        {
            x+=y;
            sum+=y;
            xxor/=2;
            xxor^=y;
            xxor*=2;
        }
        ans.push_back(x);

    }

    int z=xxor-sum;
    z/=2;
    ans.push_back(z);
    ans.push_back(z);

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}