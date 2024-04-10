/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int Infy = 1e10;

void solve()
{
    string s, t;
    cin>>s>>t;

    int n = s.size(), m = t.size();

    int cost[27][27];
    for(int i=1; i<=26; i++)
    {
        for(int j=1; j<=26; j++) cost[i][j]=Infy;
        cost[i][i]=0;
    }

    int l; cin>>l;
    for(int i=1; i<=l; i++)
    {
        char x, y; int w;
        cin>>x>>y>>w;
        int xx = x-'a'+1; int yy = y-'a'+1;
        cost[xx][yy] = min(cost[xx][yy], w);
    }

    if(n!=m) { cout<<-1<<endl; return; }

    for(int k=1; k<=26; k++)
    {
        for(int i=1; i<=26; i++)
        {
            for(int j=1; j<=26; j++) cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
        }
    }

    string f;
    int ans=0;

    for(int i=0; i<n; i++)
    {
        int x = s[i]-'a'+1;
        int y = t[i]-'a'+1;
        char mni = 5;
        int mnv = Infy;

        for(int j=1; j<=26; j++)
        {
            if(cost[x][j]+cost[y][j]<mnv)
            {
                mnv = cost[x][j]+cost[y][j];
                mni = 'a'+j-1;
            }
        }

        ans+=mnv;
        f+=mni;
    }

    if(ans>=Infy) cout<<-1<<endl;
    else cout<<ans<<endl<<f<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}