/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int max_con1(vector<int> a)
{
    int n = a.size();

    int all1=1;
    for(int i=0; i<n; i++)
    {
        if(a[i]==0) all1=0;
        a.push_back(a[i]);
    }

    if(all1) return -1;

    int ans=0, cnt=0;
    for(int i=0; i<(2*n); i++)
    {
        if(a[i]==0) cnt=0;
        else cnt++;
        ans = max(ans, cnt);
    }

    return ans;
}

int solve()
{
    int n, d;
    cin>>n>>d;

    int a[n+1];
    for(int i=0; i<n; i++) cin>>a[i];

    int vis[n+1]={0}, ans=0;
    for(int i=0; i<n; i++)
    {
        if(vis[i]==1) continue;

        int j=i;
        vector<int> b;
        while(vis[j]==0)
        {
            b.push_back(a[j]);
            vis[j]=1;

            int nxt = (j-d+n)%n;
            j=nxt;
        }

        int tmp = max_con1(b);
        if(tmp==-1) return -1;
        ans = max(ans, tmp);
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) cout<<solve()<<endl;
    return 0;
}