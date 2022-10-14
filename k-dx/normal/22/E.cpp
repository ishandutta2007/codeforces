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

int n,
    next_component = 1,
    which_component[N];
bool vis[N];
vector<int> graf[N],
            reversed_graf[N],
            scc_graf[N],
            topo,
            topo_scc,
            component;
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

void dfs1_scc (int v) {
    //printf("dfs %d\n", v);
    vis[v] = 1;

    for (int u : scc_graf[v]) {
        if (!vis[u]) dfs1_scc(u);
    }

    topo_scc.pb(v);
}

void sort_topo_scc () {
    fill(vis, vis+n+1, false);
    for (int i = 1; i < next_component; i++) {
        if (vis[i] == 0) {
            //printf("zaczynam w %d\n", i);
            dfs1_scc(i);
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

int dfs3 (int v) {
    vis[v] = 1;

    for (int u : scc_graf[v]) {
        if (!vis[u]) return dfs3(u);
    }
    return v;
}

int main () {
    scanf("%d", &n);
#ifdef spr
    printf("%d\n", n);
#endif
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
#ifdef spr
        printf("%d ", a);
#endif

        graf[i].pb(a);
        reversed_graf[a].pb(i);
    }

#ifdef spr
    printf("\n");
#endif

    sort_topo();

    scc();

    // stworz graf scc
    for (int v = 1; v <= n; v++) {
        for (int u : graf[v]) {
            logg(v, u);
            if (which_component[v] != which_component[u]) {
                scc_graf[which_component[v]].pb(which_component[u]);
                deb("%d -> %d\n", which_component[v], which_component[u]);
            }
        }
    }

    sort_topo_scc();

#ifdef D
    for (int i = topo_scc.size()-1; i >= 0; i--) {
        int v = topo_scc[i];
        printf("( "); 
        for (int e : component_list[v]) {
            printf("%d ", e);
        }
        printf(")"); 
    }
    printf("\n");
#endif

    vector<pair<int,int>> ans;
    fill(vis, vis+n+1, false);
    logg(topo_scc.size());
    vector<int> nie_wychodzi, nie_wchodzi;
    for (int i = topo_scc.size()-1; i >= 0; i--) {
        int v = topo_scc[i];
        logg(i, v);

        // nic do niego nie wchodzi
        if (!vis[v]) {
            nie_wchodzi.pb(v);
            nie_wychodzi.pb(dfs3(v));
        }
    }

#ifdef D
    deb("ok1\n");

    for (int v : nie_wchodzi) {
        printf("( "); 
        for (int e : component_list[v]) {
            printf("%d ", e);
        }
        printf(")"); 
    }
    deb("\n");
    for (int v : nie_wychodzi) {
        printf("( "); 
        for (int e : component_list[v]) {
            printf("%d ", e);
        }
        printf(")"); 
    }
    deb("\n");
#endif

    if (next_component-1 > 1) {
        for (int i = 0; i < nie_wchodzi.size(); i++) {
            logg(i);
            int v = nie_wychodzi[i];
            int u = nie_wchodzi[(i+1) % (int)nie_wchodzi.size()];
            ans.pb({ component_list[v].front(), component_list[u].front() });
        }
    }

    // mamy wiecej niz 1 komponent
    // if (next_component-1 > 1) {
    //     ans.pb({ component_list[topo_scc.front()].front(), component_list[topo_scc.back()].front() });
    // }
    
    printf("%d\n", ans.size());
    for (auto e : ans)
        printf("%d %d\n", e.first, e.second);
    printf("\n");

	return 0;
}