#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef int ll;

int n, m;
int a[10][10];

int f(int x, int y)
{
    if ((x==n) and (y==m))
        return a[n][m];
    if (x == n)
        return a[x][y] + f(x, y+1);
    if (y == m)
        return a[x][y] + f(x+1, y);

    if (a[x+1][y] != a[x][y+1])
    {
        if (a[x+1][y])
            return a[x][y] + f(x+1, y);
        else
            return a[x][y] + f(x, y+1);
    }

    return a[x][y] + f(x, y+1);

}

main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<m; j++)
            a[i][j+1] = (s[j] == '*');
    }
    cout<<f(1, 1)<<"\n";


}