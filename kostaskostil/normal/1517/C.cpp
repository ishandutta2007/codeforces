#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 1000;

int a[nmax][nmax];
int v[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>v[i], a[i][i]=v[i];
    for (int l = 2; l<=n; l++) /// >=l
    {
        bool was = (a[l-1][1] < l);
        for (int i=1; i<=n-l+1; i++)
        {
            int x = i + l-1;
            int y = i;

            if (was)
                a[x][y] = a[x][y+1];
            else
                a[x][y] = a[x-1][y];

            if (a[x][y+1] < l)
                was = true;
        }
    }
    for (int i=1; i<=n; i++, cout<<"\n")
        for (int j=1; j<=n; j++)
            if (i >= j)
            cout<<a[i][j]<<" ";
}