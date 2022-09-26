#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        bool s = false;
        if (n%2 != 0)
        {
            swap(n, m);
            k = n*m/2 - k;
            s = true;
        }

        vector<vector<char> > v(n, vector<char>(m, 0));
        for (int i=0; i < n; i+=2)
            for (int j=0; j<m; j++)
                v[i][j] = v[i+1][j] = 'a' + 4 * ((i+j)%5) + (abs(i-j)%5);
        for (int i = 0; i < n; i+=2)
            for (int j=0; j+1 < m; j+=2)
                if (k>=2)
        {
            k-=2;
            swap(v[i][j+1], v[i+1][j]);
        }
        if (k==0)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
}