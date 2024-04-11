#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 4e5+100;

typedef long long ll;
#define int ll

int n;
bool up[nmax];
int op[nmax];
int pos[nmax];
int id[nmax];
vector<int> groupby[nmax];

void panic()
{
    cout<<"-1\n";
    exit(0);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int x, y, i=1; i<=n; i++)
    {
        cin>>x>>y;
        op[x]=y;
        op[y]=x;
        up[x] = true;
    }

    vector<int> order;
    for (int i=1; i<=n; i++)
    {
        order.pb(i);
        order.pb(2*n+1-i);
    }

    set<int> lt;
    int cnt = 0;
    int upmax, upmin, downmax, downmin;
        upmax = 1e9;
        upmin = -1e9;
        downmax = 1e9;
        downmin = -1e9;
    for (int i : order)
    {
        if (lt.size() == 0)
        {
            if ((upmin > upmax) or (downmin > downmax))
                panic();
            cnt++;
            upmax = 1e9;
            upmin = -1e9;
            downmax = 1e9;
            downmin = -1e9;
        }
        id[i] = cnt;
        if (lt.count(i))
        {
            lt.erase(i);
            continue;
        }

        if (i<=n)
        {
            if ((i < upmin) or (op[i] > downmax))
                panic();
            pos[i] = 1;
            pos[op[i]]=-1;
            lt.insert(op[i]);

            upmin = i;
            downmax = op[i];
        }
        else
        {
            if ((i > upmax) or (op[i] < downmin))
                panic();
            pos[i] = 1;
            pos[op[i]]=-1;
            lt.insert(op[i]);

            upmax = i;
            downmin = op[i];
        }
    }
    if ((upmin > upmax) or (downmin > downmax))
        panic();

    int ans=0;
    for (int i=1; i<=2*n; i++)
        groupby[id[i]].pb(i);
    for (int i=1; i<=cnt; i++)
    {
        int c = groupby[i].size()/2;

        int t = 0;
        for (int j : groupby[i])
            if (up[j])
                if (pos[j] == 1)
                    t++;

        ans+=min(t, c-t);
    }

    cout<<ans<<"\n";
}