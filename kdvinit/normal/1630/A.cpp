/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    if(n==4)
    {
        if(k==0)
        {
            cout<<0<<" "<<3<<endl;
            cout<<1<<" "<<2<<endl;
        }
        if(k==1)
        {
            cout<<1<<" "<<3<<endl;
            cout<<0<<" "<<2<<endl;
        }
        if(k==2)
        {
            cout<<2<<" "<<3<<endl;
            cout<<0<<" "<<1<<endl;
        }
        if(k==3) cout<<-1<<endl;

        return;
    }

    int m=0;
    int tmp = n;
    while(tmp!=1) { tmp/=2; m++; }

    vector<int> p1, p2;
    int vis[n+1]={0};

    p1.push_back(0);
    vis[0]=1; vis[n-1]=1;

    for(int i=0; i<m; i++)
    {
        int cur = 1<<i;

        vis[cur]=1;
        vis[n-1-cur]=1;

        if(k&cur)
        {
            p1.push_back(cur);
        }
        else
        {
            p2.push_back(cur);
        }
    }

    int pp = p1.size();
    for(int i=0; i<pp; i++)
    {
        int x = p1[i];
        int j = (i+1)%pp;
        int y = p1[j];
        cout<<x<<" "<<n-1-y<<endl;
    }

    for(int x: p2)
    {
        cout<<x<<" "<<n-1-x<<endl;
    }

    for(int i=0; i<n; i++)
    {
        if(vis[i]==1) continue;
        cout<<i<<" "<<n-1-i<<endl;
        vis[i]=1;
        vis[n-1-i]=1;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}