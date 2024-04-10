/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int f[n+1]={0};
    vector<int> pos[n+1];

    for(int i=1; i<=n; i++)
    {
        int x = a[i];
        int j = ++f[x];
        pos[j].push_back(i);
    }

    int b[n+1];

    int pp[n+1];

    for(int i=1; i<=n; i++)
    {
        int m = pos[i].size();

        vector<int> num;

        for(int j=0; j<m; j++)
        {
            int cp = pos[i][j];
            int cn = a[cp];
            num.push_back(cn);
            pp[cn]=cp;
        }

        sort(num.begin(), num.end());

        for(int j=0; j<m; j++)
        {
            int cn = num[j];
            int nj = (j+1)%m;
            int nn = num[nj];
            int np = pp[nn];
            b[np] = cn;
        }
    }

    for(int i=1; i<=n; i++) cout<<b[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}