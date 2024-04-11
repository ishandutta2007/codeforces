#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
//const int nmax=5e5+100;
#define int long long
int n, m, k;

int a[1010][1010];
int up1[1010][1010];
int up0[1010][1010];
int dn1[1010][1010];
int dn0[1010][1010];
int pref1[1010][1010];
int pref0[1010][1010];
int suf1[1010][1010];
int suf0[1010][1010];

int dist(int x, int y){
    if (a[x][y]) return min(pref0[x][y]-(n-x), suf0[x][y]-x);
    else return min(pref1[x][y]-(n-x), suf1[x][y]-x);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;

    string s;
    for (int i=1; i<=n; i++)
    {
        cin>>s;
        for (int j=1; j<=m; j++)
            a[i][j]=(s[j-1]=='1');
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            a[i][j]=(a[i][j]+i+j)%2;

    for (int i=1; i<=n; i++)
    {
        dn1[i][0]=dn0[i][0]=1e4;
        for (int j=1; j<=m; j++){
            dn1[i][j]=dn1[i][j-1]+1;
            dn0[i][j]=dn0[i][j-1]+1;
            if (a[i][j]==1) dn1[i][j]=0;
            else dn0[i][j]=0;
        }
        up1[i][m+1]=up0[i][m+1]=1e4;
        for (int j=m; j>=1; j--){
            up1[i][j]=up1[i][j+1]+1;
            up0[i][j]=up0[i][j+1]+1;
            if (a[i][j]==1) up1[i][j]=0;
            else up0[i][j]=0;
        }
    }

//    for (int i=1; i<=n; i++, cout<<"\n")
//    for (int j=1; j<=m; j++)
//        cout<<up1[i][j]<<" ";

    for (int j=1; j<=m; j++){
        pref1[0][j]=pref0[0][j]=1e4;
        for (int i=1; i<=n; i++)
        {
            pref0[i][j]=min(pref0[i-1][j], n-i+min(up0[i][j], dn0[i][j]));
            pref1[i][j]=min(pref1[i-1][j], n-i+min(up1[i][j], dn1[i][j]));
        }
        suf1[n+1][j]=suf0[n+1][j]=1e4;
        for (int i=n; i>=1; i--)
        {
            suf0[i][j]=min(suf0[i+1][j], i+min(up0[i][j], dn0[i][j]));
            suf1[i][j]=min(suf1[i+1][j], i+min(up1[i][j], dn1[i][j]));
        }
    }
//    for (int i=1; i<=n; i++, cout<<"\n")
//    for (int j=1; j<=m; j++)
//    cout<<pref1[i][j]<<" ";
//    for (int i=1; i<=n; i++, cout<<"\n")
//    for (int j=1; j<=m; j++)
//    cout<<suf0[i][j]<<" ";
/*
4 4 0
0011
1111
1110
1000
*/
//    for (int i=1; i<=n; i++, cout<<"\n")
//    for (int j=1; j<=m; j++)
//    cout<<dist(i, j)<<" ";
    for (int i=1; i<=k; i++){
        int x, y, p;
        cin>>x>>y>>p;
        int d=dist(x, y);
        if ((d>m+n) or (d>p))
            cout<<(a[x][y]+x+y)%2<<"\n";
        else
            cout<<(a[x][y]+(p-d+1)+x+y)%2<<"\n";
    }

    return 0;
}