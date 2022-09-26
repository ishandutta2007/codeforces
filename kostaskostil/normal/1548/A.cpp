#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 1e6+100;

int cnt[nmax];
int ans = 0;

void add(int x, int y)
{
    if (x>y)
        swap(x, y);

    if (cnt[x]==0)
        ans++;
    cnt[x]++;
}

void del(int x, int y)
{
    if (x>y)
        swap(x, y);

    cnt[x]--;
    if (cnt[x]==0)
        ans--;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        add(x, y);
    }
    int q;
    cin>>q;
    while (q--)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int x, y;
            cin>>x>>y;
            add(x, y);
        }
        if (t==2)
        {
            int x, y;
            cin>>x>>y;
            del(x, y);
        }
        if (t==3)
            cout<<n-ans<<"\n";
    }
}