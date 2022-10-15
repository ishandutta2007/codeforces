/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1e3+10;
int a[N][N];

int len(int i, int j, int dx, int dy, int strt)   // strt = 0 = i else j
{
    int ans=0;
    while(a[i][j]==0)
    {
        ans++;
        if(strt==0) i+=dx;
        else j+=dy;
        strt = !strt;
    }
    return ans;
}

int nC2(int n)
{
    int ans = (n*(n-1))/2;
    return ans;
}

void solve()
{
    int n,m, q;
    cin>>n>>m>>q;

    int tot=0;
    int dpl[n+2][m+2];
    int dpr[n+2][m+2];

    memset(dpl, 0, sizeof(dpl));
    memset(dpr, 0, sizeof(dpr));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            tot+=dpl[i][j]; tot+=dpr[i][j]; tot++;
            dpl[i][j]++; dpr[i][j]++;
            dpr[i][j+1]=dpl[i][j];
            dpl[i+1][j]=dpr[i][j];
        }
    }

    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=m+1; j++)
        {
            if(i<1 || i>n || j<1 || j>m) a[i][j]=1;
            else a[i][j]=0;
        }
    }

    while(q--)
    {
        int u, v;
        cin>>u>>v;

        int l1 = len(u-1, v, -1, -1, 1);
        int l2 = len(u, v-1, -1, -1, 0);
        int l3 = len(u+1, v, 1, 1, 1);
        int l4 = len(u, v+1, 1, 1, 0);

        if(a[u][v]==0)
        {
            a[u][v]=1;
            tot -= nC2(l1+l4+1);
            tot -= nC2(l2+l3+1);
            tot += nC2(l1); tot += nC2(l2);
            tot += nC2(l3); tot += nC2(l4);
            tot--;
        }
        else
        {
            a[u][v]=0;
            tot += nC2(l1+l4+1);
            tot += nC2(l2+l3+1);
            tot -= nC2(l1); tot -= nC2(l2);
            tot -= nC2(l3); tot -= nC2(l4);
            tot++;
        }

        cout<<tot<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}