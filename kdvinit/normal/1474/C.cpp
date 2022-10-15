/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int inf=1e16;

void solve()
{
    int n;
    cin>>n;

    int a[2*n+1];
    for(int i=1;i<=2*n;i++) cin>>a[i];

    sort(a+1,a+2*n+1);
    for(int i=1;i<2*n;i++)
    {
        multiset<int> b;
        for(int j=1;j<2*n;j++)
        {
            if(i==j) continue;
            b.insert(a[j]);
        }

        int val=a[2*n],cnt=0;
        pair<int,int> ans[n+1];
        ans[++cnt]={a[2*n],a[i]};

        while(b.size()!=0)
        {
            int x=*(b.rbegin());
            b.erase(b.find(x));

            int y=val-x;
            if(b.count(y)==0) break;
            b.erase(b.find(y));
            ans[++cnt]={x,y};
            val=x;
        }

        if(b.size()==0)
        {
            cout<<"YES"<<endl;
            cout<<a[2*n]+a[i]<<endl;
            for(int j=1;j<=n;j++)
            {
                cout<<ans[j].first<<" "<<ans[j].second<<endl;
            }
            return;
        }
    }

    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}