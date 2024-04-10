/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    vector<int> blocks;
    for(int i=1;i<=n;i++)
    {
        int siz=0;
        int j=i;
        while(a[i]==a[j]) { i++; siz++; }
        i--;
        blocks.push_back(siz);
    }

    int  m=blocks.size();
    sort(blocks.begin(),blocks.end());

    int sum[m];
    int cur=0;

    for(int i=0;i<m;i++)
    {
        //cout<<blocks[i]<<" ";
        cur+=blocks[i];
        sum[i]=cur;
    }
    //cout<<endl;

    int ans=n;
    for(int i=0;i<m;i++)
    {
        int strt=i;
        int j=i;
        while(i<m && blocks[i]==blocks[j]) i++;
        i--;
        int nd=i;

        int bk=sum[strt]-blocks[strt];
        int fr1 = (n-sum[nd]);
        int fr2 = (blocks[strt]*(m-1-nd));

        //cout<<strt<<" "<<nd<<" "<<bk<<" "<<fr1<<" "<<fr2<<endl;
        int tmp=bk+fr1-fr2;
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}