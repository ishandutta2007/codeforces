#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax =  200500;
const int amax = 2500500;

int a[nmax];
vector<pair<int, int> > pos[2*amax];

int randint()
{
    return (rand()<<15)+rand();
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    while (clock()*1.0 / CLOCKS_PER_SEC < 0.8)
    {
        int x = randint()%n + 1;
        int y = randint()%n + 1;
        if (x==y)
            continue;
        int s = a[x]+a[y];
        for (auto pa : pos[s])
            if (pa.fi != x and pa.se != x and pa.fi != y and pa.se != y)
            {
                cout<<"YES\n"<<x<<" "<<y<<" "<<pa.fi<<" "<<pa.se<<"\n";
                return 0;
            }
        pos[s].pb({x, y});
    }
    cout<<"NO\n";
    return 0;
}