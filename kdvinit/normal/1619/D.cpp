/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = (1e5)+5;
vector<int> gif[N];
int n, m;

bool check(int l)
{
    map<int, int> mp;
    int pos=0;

    for(int i=1; i<=n; i++)
    {
        int np=1;
        for(int j=0; j<m; j++)
        {
            int x = gif[i][j];
            if(x<l) continue;
            np=0;
            if(mp[j]==1) pos=1;
            mp[j]=1;
        }
        if(np==1) return false;
    }

    if(pos==1) return true;
    else return false;
}

void solve()
{
    cin>>m>>n;
    for(int i=1; i<=n; i++) gif[i].clear();

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int x; cin>>x;
            gif[j].push_back(x);
        }
    }

    int l=0, r=1e9+1;
    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }

    cout<<l<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}