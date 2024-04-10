/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+2][m+2];
    memset(a, 0, sizeof(a));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            if(x=='*') a[i][j]=1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==0) continue;

            int cnt=0;
            cnt+=a[i-1][j];
            cnt+=a[i+1][j];
            cnt+=a[i][j-1];
            cnt+=a[i][j+1];

            if(cnt>2) return false;
            if(cnt==0) return false;

            int ci=i;
            int cj=j;

            if(cnt==1)
            {
                if(a[i-1][j]==1) { ci=i-1; cj=j; }
                if(a[i+1][j]==1) { ci=i+1; cj=j; }
                if(a[i][j-1]==1) { ci=i; cj=j-1; }
                if(a[i][j+1]==1) { ci=i; cj=j+1; }
            }

            cnt=0;
            cnt+=a[ci-1][cj];
            cnt+=a[ci+1][cj];
            cnt+=a[ci][cj-1];
            cnt+=a[ci][cj+1];

            if(cnt!=2) return false;

            if( (a[ci-1][cj]+a[ci+1][cj]) != 1) return false;

            int lx, ly, tx, ty;
            if( (a[ci-1][cj]+a[ci][cj+1]) == 2) { lx=ci-2; ly=cj+2; tx=ci-2; ty=cj-1; }
            if( (a[ci+1][cj]+a[ci][cj+1]) == 2) { lx=ci+2; ly=cj+2; tx=ci-1; ty=cj-1; }
            if( (a[ci+1][cj]+a[ci][cj-1]) == 2) { lx=ci+2; ly=cj-2; tx=ci-1; ty=cj-2; }
            if( (a[ci-1][cj]+a[ci][cj-1]) == 2) { lx=ci-2; ly=cj-2; tx=ci-2; ty=cj-2; }

            int tot=0;
            for(int i1=tx; i1<=tx+3; i1++)
            {
                for(int i2=ty; i2<=ty+3; i2++) tot+=a[i1][i2];
            }
            tot-=a[lx][ly];

            if(tot!=3) return false;
        }
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

/*
1
3 2
..
**
*.
*/