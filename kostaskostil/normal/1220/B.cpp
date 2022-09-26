#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int nmax=1e3+100;
#define int long long

int n;
int a[nmax][nmax];
int b[nmax];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin>>a[i][j];
    for (int i=1; i<=n-2; i++)
    {
        double s=sqrt(a[i][i+1]*a[i][i+2]);
        s*=sqrt(a[i+1][i+2]);
        int r=s+0.5;
        b[i]=(r+a[i+1][i+2]/2)/a[i+1][i+2];
        b[i+1]=(r+a[i][i+2]/2)/a[i][i+2];
        b[i+2]=(r+a[i][i+1]/2)/a[i][i+1];
    }
    for (int i=1; i<=n; i++)
        cout<<b[i]<<" ";
    cout<<"\n";
}