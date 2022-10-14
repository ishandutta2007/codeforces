#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 1e6+5;

int n, m;
int t[N];
vector<int> graf[N];
bool vis[N];
vector<int> spojna;

void dfs (int v) {
    vis[v] = true;
    spojna.pb(v);

    for (int u : graf[v]) {
        if (!vis[u])
            dfs(u);
    }
}

int main () {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;

        graf[a].pb(b);
        graf[b].pb(a);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            spojna.clear();
            dfs(i);

            vector<int> lista;
            for (int e : spojna)
                lista.pb(t[e]);

            sort(spojna.begin(), spojna.end());
            sort(lista.begin(), lista.end(), greater<int>());

            for (int j = 0; j < (int)spojna.size(); j++) {
                t[spojna[j]] = (lista[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }

    return 0;
}