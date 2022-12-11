#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 10;

int h[nmax][nmax];

int gg(const vector<int>& a) {
    if (sz(a) <= 1) {
        return 0;
    }
    /*int x = 0;
    for (int i = 0; i < sz(a); ++i) {
        for (int j = i + 1; j < sz(a); ++j) {
            if (h[a[i]][a[j]]) {
                ++x;
            }
        }
    }
    return x;*/
    cout << "? " << sz(a) << "\n";
    for (int x : a) {
        cout << x + 1 << " ";
    }
    cout << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int get(int i, const vector<int>& a) {
    int ans = gg(a);
    vector<int> b;
    for (int x : a) {
        if (x != i) {
            b.pb(x);
        }
    }
    ans -= gg(b);
    return ans;    
}

int getVertex(int v, const vector<int>& a) {
    int l = 0, r = sz(a);
    while (r - l > 1) {
        int md = (l + r) >> 1;
        vector<int> vct = {v};
        for (int i = l; i < md; ++i) {
            vct.pb(a[i]);
        }
        int z = get(v, vct);
        if (z) {
            r = md;
        } else {
            l = md;
        }
    }
    int z = get(v, {v, a[l]});
    assert(z);
    return a[l];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    /*int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        h[u][v] = h[v][u] = 1;
    }*/

    vector<vector<int> > g(n);
    vector<vector<int> > part[2];
    vector<int> color(n, -1);

    for (int i = 0; i < n; ++i) {
        //cout << "AL " << i + 1 << endl;
        vector<int> vct;
        for (int j = 0; j <= i; ++j) {
            vct.pb(j);
        }
        int cnt = get(i, vct);
        if (cnt == 0) {
            vector<int> tmp;
            part[1].pb(tmp);
            tmp.pb(i);
            part[0].pb(tmp);
            continue;
        }
        int l = 0, r = sz(part[0]);
        while (r - l > 1) {
            int md = (l + r) >> 1;
            //cout << "!" << md << endl;
            vct = {i};
            for (int j = l; j < md; ++j) {
                for (int x : part[0][j]) {
                    vct.pb(x);
                }
                for (int x : part[1][j]) {
                    vct.pb(x);
                }
            }
            
            int z = get(i, vct);
            if (z) {
                r = md;
            } else {
                l = md;
            }
        }

        swap(part[0][0], part[0][l]);
        swap(part[1][0], part[1][l]);

        int p;
        vct = {i};
        for (int x : part[0][0]) {
            vct.pb(x);
        }
        int z = get(i, vct);
        if (z) {
            p = 1;
        } else {
            p = 0;
        }

        int vertex = getVertex(i, part[p ^ 1][0]);
        g[vertex].pb(i);
        g[i].pb(vertex);

        part[p][0].pb(i);
        while (true) {
            vct = {i};
            for (int j = 1; j < sz(part[0]); ++j) {
                for (int x : part[0][j]) {
                    vct.pb(x);
                }
                for (int x : part[1][j]) {
                    vct.pb(x);
                }
            }
            z = get(i, vct);
            if (!z) {
                break;
            }
            int l = 1, r = sz(part[0]);
            while (r - l > 1) {
                int md = (l + r) >> 1;
                vct = {i};
                for (int j = l; j < md; ++j) {
                    for (int x : part[0][j]) {
                        vct.pb(x);
                    }
                    for (int x : part[1][j]) {
                        vct.pb(x);
                    }
                }
                z = get(i, vct);
                if (z) {
                    r = md;
                } else {
                    l = md;
                }
            }
            int j = l;
            vct = {};
            for (int x : part[0][j]) {
                vct.pb(x);
            }
            vct.pb(i);
            z = get(i, vct);
            swap(part[0][j], part[0].back());
            swap(part[1][j], part[1].back());
            if (z) {
                for (int x : part[0].back()) {
                    part[p ^ 1][0].pb(x);
                }
                vertex = getVertex(i, part[0].back());
                g[vertex].pb(i);
                g[i].pb(vertex);
                for (int x : part[1].back()) {
                    part[p][0].pb(x);
                }
            } else {
                for (int x : part[1].back()) {
                    part[p ^ 1][0].pb(x);
                }
                vertex = getVertex(i, part[1].back());
                g[vertex].pb(i);
                g[i].pb(vertex);
                for (int x : part[0].back()) {
                    part[p][0].pb(x);
                }
            }
            part[0].pop_back();
            part[1].pop_back();
        }

        vct = {};
        for (int x : part[p][0]) {
            vct.pb(x);
        }
        z = get(i, vct);
        if (!z) {
            continue;
        }
        vct = {};
        for (int x : part[p][0]) {
            if (x != i) {
                vct.pb(x);
            }
        }
        vertex = getVertex(i, vct);
        g[vertex].pb(i);
        g[i].pb(vertex);
        /*for (int a = 0; a < n; ++a) {
            for (int to : g[a]) {
                cout << a << " " << to << endl;
            }
        }*/
        vector<int> parent(n, -1);
        color[i] = 0;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            //cout << "!!" << v << endl;
            for (int to : g[v]) {
                if (color[to] == -1) {
                    color[to] = 1 - color[v];
                    parent[to] = v;
                    q.push(to);
                }
            }
        }



        for (int a = 0; a < n; ++a) {
            if (color[a] == -1) {
                continue;
            }
            for (int to : g[a]) {
                if (color[to] == color[a]) {
                    vector<vector<int> > u;
                    vector<int> t = {a, to};
                    for (int st : t) {
                        int curr = st;
                        vct = {};
                        while (parent[curr] != -1) {
                            vct.pb(curr);
                            curr = parent[curr];
                        }
                        vct.pb(i);
                        u.pb(vct);
                    }
                    while (sz(u[0]) >= 2 && sz(u[1]) >= 2 && u[0].back() == u[1].back() && u[0][sz(u[0]) - 2] == u[1][sz(u[1]) - 2]) {
                        u[0].pop_back();
                        u[1].pop_back();
                    }
                    assert(u[0].back() == u[1].back());
                    u[1].pop_back();
                    reverse(all(u[1]));
                    vct = u[0];
                    for (int x : u[1]) {
                        vct.pb(x);
                    }
                    //reverse(all(vct));
                    cout << "N ";
                    cout << sz(vct) << "\n";
                    for (int x : vct) {
                        cout << x + 1 << " ";
                    }
                    cout << "\n";
                    cout.flush();
                    return 0;
                }
            }
        }
    }

    vector<int> vct;
    for (int i = 0; i < sz(part[0]); ++i) {
        for (int x : part[0][i]) {
            vct.pb(x);
        }
    }

    cout << "Y " << sz(vct) << "\n";
    for (int x : vct) {
        cout << x + 1 << " ";
    }
    cout << "\n";
    cout.flush();
    
}