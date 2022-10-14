// inspirowane kodem z
// https://cp-algorithms.com/graph/strongly-connected-components.html
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

const int N = 1e5+5;
const int MOD = 1'000'000'007;

int n, m, next_component = 1, which_component[N], in_deg[N], ile = 0, cost[N];
bool vis[N];
// scc_graf ma odwrocone krawedzie wzgledem oryginalnego grafu
vector<int> graf[N], reversed_graf[N], topo, component, scc_graf[N];
vector<vector<int>> component_list;

void dfs1 (int v) {
    //printf("dfs %d\n", v);
    vis[v] = 1;

    for (int u : graf[v]) {
        if (!vis[u]) dfs1(u);
    }

    topo.pb(v);
}

void sort_topo () {
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            //printf("zaczynam w %d\n", i);
            dfs1(i);
        }
    }
}

void dfs2 (int v) {
    vis[v] = 1;
    component.pb(v);
    
    for (int u : reversed_graf[v]) {
        if (!vis[u]) dfs2(u);
    }
}

void scc () {
    next_component = 1;
    component_list.resize(1);
    fill(vis, vis+n+1, false);
    for (int i = topo.size()-1; i >= 0; i--) {
        int v = topo[i];
        if (!vis[v]) {
            dfs2(v);
        }

        if (!component.empty()) {
            deb("next component:\n");
            component_list.pb(component);
            for (int e : component) {
                deb("%d ", e);
                which_component[e] = next_component;
            }
            deb("\n");
            next_component++;
        }

        component.clear();
    }
}

void dfs3 (int v) {
    vis[v] = true;
    ile++;

    for (int u : scc_graf[v])
        if (!vis[u])
            dfs3(u);
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graf[a].pb(b);
        reversed_graf[b].pb(a);
    }

    sort_topo();

    /*
    printf("Posortowanie topologiczne (krawedzie wskazuja tylko w prawo):\n");
    for (int i = topo.size()-1; i >= 0; i--) {
        printf("%d ", topo[i]);
    }
    printf("\n");
    */

    scc();

    // stworz odwrocony graf scc
    // for (int v = 1; v <= n; v++) {
    //     for (int u : graf[v]) {
    //         if (which_component[v] != which_component[u]) {
    //             scc_graf[which_component[u]].pb(which_component[v]);
    //             deb("%d -> %d\n", which_component[u], which_component[v]);
    //         }
    //     }
    // }

    logg(next_component);

    ll ways = 1LL;
    ll min_cost = 0LL;
    for (int i = 1; i < next_component; i++) {

        int component_min_cost = INT_MAX;
        for (int e : component_list[i]) {
            component_min_cost = min(component_min_cost, cost[e]);
        }
        int ile_minimow = 0;
        for (int e : component_list[i]) {
            if (cost[e] == component_min_cost) ile_minimow++;
        }

        logg(ile_minimow);
        ways *= (ll)ile_minimow;
        ways %= (ll)MOD;

        min_cost += (ll)component_min_cost;
    }

    printf("%lld %lld\n", min_cost, ways);
		
	return 0;
}