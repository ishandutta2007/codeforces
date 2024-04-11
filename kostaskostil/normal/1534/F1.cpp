#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 5e5 + 100;

typedef long long ll;
#define int ll

int n, m;
set<int> pos[nmax];
int c = 0;
map<pair<int, int>, int> ind;
vector<pair<int, int> > sand;
vector<int> g[nmax];

vector <int> gr[nmax];
vector<char> used;
vector<int> order, component;

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;
    for (int j=0; j<m; j++)
    {
        string s;
        cin>>s;
        for (int i = 0; i < n; i++)
            if (s[i] == '#')
            {
                pos[i].insert(j);
                sand.pb({i, j});
                ind[{i, j}] = c++;
            }
    }

    for (int i=0; i<c; i++)
    {
        auto [x, y] = sand[i];
        if (ind.count({x, y-1}))
            g[i].pb(ind[{x, y-1}]);
        if (x > 0)
        if (pos[x-1].lower_bound(y) != pos[x-1].end())
            g[i].pb(ind[{x-1, *pos[x-1].lower_bound(y)}]);
        if (pos[x].upper_bound(y) != pos[x].end())
            g[i].pb(ind[{x, *pos[x].upper_bound(y)}]);
        if (pos[x+1].lower_bound(y) != pos[x+1].end())
            g[i].pb(ind[{x+1, *pos[x+1].lower_bound(y)}]);
    }
    for (int i=0; i<c; i++)
        for (int j : g[i])
            gr[j].pb(i);

//    for (int i=0; i<c; i++)
//    for (int j: g[i])
//        cout<<i<<" "<<j<<"\n";

    map<int, int> cmp;
    int cmpx = 0;

    used.assign (c, false);
	for (int i=0; i<c; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (c, false);
	for (int i=0; i<c; ++i) {
		int v = order[c-1-i];
		if (!used[v]) {
            dfs2 (v);
            for (int i : component)
                cmp[i] = cmpx;
            cmpx++;
			component.clear();
		}
	}
    vector<int> notin(cmpx, 1);
    for (int i=0; i<c; i++)
        for (int j : g[i])
            if (cmp[i] != cmp[j])
                notin[cmp[j]] = 0;
    int ans=0;
    for (int i: notin)
        if (i ==1)
            ans++;
    cout<<ans<<"\n";
}