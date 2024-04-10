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

const int N = 1e5+5;
const int M = 1e5+5;

int n, m;
bitset<N> status;
vector<int> door[N];

vector<int> graf[2*N];
bitset<2*N> vis;
vector<int> topo_stack;

int spojna[2*N];

void topo_dfs (int v) {
    vis[v] = true;
    for (int u : graf[v])
        if (!vis[u]) 
            topo_dfs(u);

    topo_stack.pb(v);
}

void topo_sort () {
    for (int i = 1; i <= 2*m; i++)
        if (!vis[i])
            topo_dfs(i);

    //reverse(topo_stack.begin(), topo_stack.end());
}

void scc_dfs (int v, int nr_spojnej) {
    vis[v] = true;
    spojna[v] = nr_spojnej;
    for (int u : graf[v])
        if (!vis[u]) 
            scc_dfs(u, nr_spojnej);
}

void scc () {
    //fill(vis, vis + 2*n+2, false);
    vis.reset();
    int nr_spojnej = 1;
    for (int i = 0; i < (int)topo_stack.size(); i++) {
        if (!vis[topo_stack[i]]) {
            scc_dfs(topo_stack[i], nr_spojnej++);
        }
    }
}

int main () {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int s;
        scanf("%d", &s);
        status[i] = s;
    }

    if (status.count() == n) {
        printf("YES\n");
        exit(0);
    }

    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 1; j <= x; j++) {
            int d;
            scanf("%d", &d);
            door[d].pb(i);
            deb("drzwi nr %d kontrolowane przez %d\n", d, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        int a = door[i][0];
        int b = door[i][1];
        deb("drzwi %d kontrolowane przez %d i %d\n", i, a, b);
        for (int e : door[i])
            deb("%d ", e);
        deb("\n");
        if (status[i] == 1) { // otwarte
            // a => b
            graf[a].pb(b);
            // !b => !a
            graf[b+n].pb(a+m);
            
            // b => a
            graf[b].pb(a);
            // !a => !b
            graf[a+m].pb(b+m);
        }
        else { // zamkniete
            // a => !b
            graf[a].pb(b+m);
            // b => !a
            graf[b].pb(a+m);

            // !b => a
            graf[b+m].pb(a);
            // !a => b
            graf[a+m].pb(b);
        }
    }

    topo_sort();
    scc();

    bool ok = true;
    for (int i = 1; i <= m; i++) {
        if (spojna[i] == spojna[i+m]) {
            ok = false;
            deb("nieok dla: %d\n", i);
        }
    }

    if (ok) printf("YES\n");
    else printf("NO\n");

    // cout << sizeof(bool) << endl;
    // cout << sizeof(int) << endl;



    return 0;
}