#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd ; exit(0)
#define double long double

using namespace std;

const int MAXN = 2e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

vector<int> g[MAXN];
int color[MAXN];
bool used[MAXN];
int tekcolor = 1;

void dfs(int v, int prev = -1){
    tekcolor = max(tekcolor, color[v]);
    used[v] = 1;
    vector<pr<int,int> > obh;
    int tek = 0;
    for (auto to : g[v]){
        if (!used[to]){
            tek++;
            while (tek == color[v] || tek == prev){
                    tek++;
            }
            obh.pb(mp(to, tek));
        }
    }
    for (auto to : obh){
        color[to.fs] = to.sc;
        dfs(to.fs, color[v]);
    }
}

main() {
	//freopen("kek.in", "r", stdin);
	//freopen("kek.out", "w", stdout);
	ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    color[0] = 1;
    dfs(0);
    cout << tekcolor << endl;
    for (int i = 0; i < n; i++){
        cout << color[i] << ' ';
    }
}