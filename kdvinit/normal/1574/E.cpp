/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define endl "\n"

const int mod = 998244353;

set<int> row[3], col[3];        //0 = not poss, 1 = 1 way poss, 2 = 2 ways possible

void set_row(int r, int cnt)
{
    for(int i=0; i<3; i++)
    {
        if(i==cnt) row[i].insert(r);
        else row[i].erase(r);
    }
}

void set_col(int c, int cnt)
{
    for(int i=0; i<3; i++)
    {
        if(i==cnt) col[i].insert(c);
        else col[i].erase(c);
    }
}

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    int l = max(n, m);
    int p2[l+1];

    p2[0]=1;
    for(int i=1; i<=l; i++) p2[i] = (p2[i-1]*2)%mod;

    for(int i=1; i<=n; i++) row[2].insert(i);
    for(int i=1; i<=m; i++) col[2].insert(i);

    int parr[n+1][2][2];      //[row][even, odd][0, 1];
    memset(parr, 0, sizeof(parr));

    int parc[m+1][2][2];      //[col][even, odd][0, 1];
    memset(parc, 0, sizeof(parc));

    int glo[2][2];      //[even, odd][0, 1];
    memset(glo, 0, sizeof(glo));

    map<pair<int, int>, int> a;

    while(k--)
    {
        int x, y, t;
        cin>>x>>y>>t;

        int z = (x+y)%2;
        int t2 = a[{x, y}]-1;

        if(t2!=-1) glo[z][t2]--;

        if(t2!=-1)
        {
            parr[x][y%2][t2]--;
            parc[y][x%2][t2]--;
        }

        if(t!=-1)
        {
            parr[x][y%2][t]++;
            parc[y][x%2][t]++;
        }

        a[{x, y}]=t+1;
        if(t!=-1) glo[z][t]++;

        int cx=0;
        if(parr[x][0][1]==0 && parr[x][1][0]==0) cx++;
        if(parr[x][1][1]==0 && parr[x][0][0]==0) cx++;

        int cy=0;
        if(parc[y][0][1]==0 && parc[y][1][0]==0) cy++;
        if(parc[y][1][1]==0 && parc[y][0][0]==0) cy++;

        set_row(x, cx);
        set_col(y, cy);

        int ans=0;

        int posr = row[0].size();
        int varr = row[2].size();

        int posc = col[0].size();
        int varc = col[2].size();

        if(posr==0) ans+=p2[varr];
        if(posc==0) ans+=p2[varc];

        if(glo[1][0]==0 && glo[0][1]==0) ans--;
        if(glo[1][1]==0 && glo[0][0]==0) ans--;

        ans%=mod;
        if(ans<0) ans+=mod;
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}