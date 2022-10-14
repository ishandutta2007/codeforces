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

const int N = 1e6+5;
const int M = 1e6+5;

struct Edge {
    int u, i;
};

int n,
    m,
    s,
    next_component = 1,
    which_component[N],
    cost[N],
    s_component; 
ll supervertex_cost[N],
   supervertex_ans[N],
   edge_cost[M],
   real_edge_cost[M];
bool vis[N],
     edge_vis[M];
vector<Edge> graf[N],
             reversed_graf[N],
             scc_graf[N];
vector<int> topo,
            component;
vector<vector<int>> component_list;

void dfs1 (int v) {
    //printf("dfs %d\n", v);
    vis[v] = 1;

    for (Edge e : graf[v]) {
        if (!vis[e.u]) dfs1(e.u);
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
    if (v == s) s_component = next_component;
    component.pb(v);
    
    for (Edge e : reversed_graf[v]) {
        if (!vis[e.u]) dfs2(e.u);
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

// ile grzybw mona zebra z krawdzi o pocztkowej liczbie grzybw w
ll m00shr00m (int w) {
    // naive !!!
    // ll res = 0LL;
    // ll sum = 0LL;
    // for (int i = 1; i < INT_MAX && w - sum > 0; i++) {
    //     res += w - sum;
    //     deb("dodaje %lld\n", w - sum);
    //     sum += (ll)i;
    // }
    // return res;

    // log time !!!
    ll beg = 0, mid, end = 15000;
    while (beg + 1 != end) {
        mid = (beg + end) / 2LL;
        ll sum = mid * (mid+1LL) / 2LL;
        if ((ll)w - sum < 0) {
            end = mid;
        }
        else {
            beg = mid;
        }
    }

    ll t = end;
    ll sum = end * (end+1LL) / 2LL;
    if ((ll)w - sum < 0) t = beg;
    
    sum = t * (t+1LL) / 2LL;

    logg(t);
    logg(sum);

    return ((ll)w-sum) * (t+1) + t*(t+1LL)*(2LL*t+1LL)/6LL;
}

void dfs3 (int v) {
    vis[v] = 1;

    for (Edge e : graf[v]) {
        int u = e.u;
        if (which_component[u] == which_component[v]) {
            if (!edge_vis[e.i]) {
                edge_vis[e.i] = 1;
                supervertex_cost[which_component[v]] += real_edge_cost[e.i];
            }
            if (!vis[u]) dfs3(u);
        }
    }

}

ll dfs4 (int v) {
    if (vis[v]) return supervertex_ans[v];

    vis[v] = 1;

    supervertex_ans[v] = supervertex_cost[v];
    for (Edge e : scc_graf[v]) {
        int u = e.u;
        supervertex_ans[v] = max(supervertex_ans[v], 
                                 dfs4(u) + edge_cost[e.i] + supervertex_cost[v]);
    }

    return supervertex_ans[v];
}

int main () {
    // int x;
    // scanf("%d", &x);
    // printf("%lld\n", m00shr00m(x));
    // return 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        logg(a, b, w);

        edge_cost[i] = w;
        real_edge_cost[i] = m00shr00m(w);
        graf[a].pb({ b, i });
        reversed_graf[b].pb({ a, i });
    }
    scanf("%d", &s);

    sort_topo();

    scc();

    // stworz graf scc
    for (int v = 1; v <= n; v++) {
        for (Edge e : graf[v]) {
            int u = e.u;
            logg(v, u);
            if (which_component[v] != which_component[u]) {
                scc_graf[which_component[v]].pb({ which_component[u], e.i });
                deb("%d -> %d\n", which_component[v], which_component[u]);
            }
        }
    }

    for (int i = 1; i < next_component; i++) {
        logg(i, supervertex_cost[i]);
    }


    fill(vis, vis+n+1, false);
    for (int i = 1; i < next_component; i++) {
        dfs3(component_list[i].front());
    }

    fill(vis, vis+n+1, false);
    printf("%lld\n", dfs4(s_component));

	return 0;
}