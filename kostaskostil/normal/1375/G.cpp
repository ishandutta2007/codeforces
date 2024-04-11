#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int> > g(n);
    for (int x, y, i=1; i<n; i++)
        cin>>x>>y, x--, y--, g[x].pb(y), g[y].pb(x);
    queue<int> q;
    vector<int> d(n, -1);
    q.push(0);
    d[0]=0;
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        for (int i:g[v])
            if (d[i]==-1)
                d[i]=d[v]+1, q.push(i);
    }
    vector<int> cnt(2);
    for (int i:d)
        cnt[i%2]++;
    cout<<min(cnt[0], cnt[1])-1<<"\n";
}