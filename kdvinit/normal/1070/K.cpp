/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1], sum=0;
    for(int i=1; i<=n; i++) cin>>a[i], sum+=a[i];

    if(sum%k!=0) { cout<<"No"<<endl; return; }
    int tot = sum/k;

    int cnt=0;
    sum=0;
    vector<int> ans;
    for(int i=1; i<=n; i++)
    {
        sum+=a[i];
        cnt++;
        if(sum>tot) { cout<<"No"<<endl; return; }
        if(sum<tot) continue;
        sum=0;
        ans.push_back(cnt);
        cnt=0;
    }
    if(sum!=0) { cout<<"No"<<endl; return; }

    cout<<"Yes"<<endl;
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}