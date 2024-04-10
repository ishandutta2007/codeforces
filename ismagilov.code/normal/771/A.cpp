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
#define endd endl; exit(0)

using namespace std;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;
const int INF = 1e9;

set<int> g[MAXN];
bool used[MAXN];
int tek = 0;
set<pr<int, int>> res;
set<pr<int, int>> nuul;

void dfs(int v){
    used[v] = 1;
    tek++;
    for (auto to : g[v]){
        if (!used[to]){
            dfs(to);
        }
        res.insert(mp(min(v, to), max(v, to)));
    }
}

main() {
    #ifdef __linux__

    #endif // __linux__
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vc<pr<int, int> > rebers;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    bool prav = 1;
    for (int i = 0; i < n; i++){
        if (!used[i]){
            tek = 0;
            res = nuul;
            dfs(i);
            if (tek * (tek - 1) / 2 != len(res)){
                prav = 0;
            }
        }
    }
    if (prav){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}