#include <bits/stdc++.h>
#define DMAX 110
using namespace std;

int n, a[DMAX], x, y, m;

void solve(int x, int y)
{
    a[x-1]+=y-1;
    a[x+1]+=a[x]-y;
    a[x]=0;
}

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        solve(x, y);
    }

        for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<'\n';
    }


    return 0;
}