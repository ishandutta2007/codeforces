#include<bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& s) {
    string res = "'";
    res += s;
    res += "'";
    return res;
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (i) res += ", ";
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

vector<long long> dijkstra(vector<vector<pair<int, long long>>>& g, int start) {
    int n = g.size();
    vector<long long> dist(n, 1e18);
    dist[start] = 0;
    set<pair<long long, int>> st;
    st.insert({0, start});
    while (st.size() > 0) {
        auto el = *st.begin();
        st.erase(el);
        int v = el.second, d = el.first;
        for (auto r : g[v]) {
            int x = r.first, d2 = r.second;
            if (d + d2 < dist[x]) {
                st.erase({dist[x], x});
                dist[x] = d + d2;
                st.insert({dist[x], x});
            }
        }
    }
    return dist;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, L, A, B;
    cin >> n >> m >> L >> A >> B;
    ve<ve<int>> R(m);
    forn (i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        R[i] = {x, y, z};
    }
    vector<vector<pii>> g;
    auto solve = [&] (int x) {
        g.clear();
        g.resize(n);
        for (auto el : R) {
            if (el[2] != 0) {
                g[el[0]].pb({el[1], el[2]});
                g[el[1]].pb({el[0], el[2]});
            }
            else {
                g[el[0]].pb({el[1], x});
                g[el[1]].pb({el[0], x});
            }
        }
        auto res = dijkstra(g, A);
        return res[B];
    };
    int l = 0, r = 1e9 + 2;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        int res = solve(mid);
        if (res > L) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    if (l == 0) {
        cout << "NO";
        return 0;
    }
    int x = l;
    l = 0, r = m;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        g.clear();
        g.resize(n);
        forn (i, m) {
            auto el = R[i];
            if (el[2] != 0) {
                g[el[0]].pb({el[1], el[2]});
                g[el[1]].pb({el[0], el[2]});
            }
            else {
                if (i < mid) {
                    g[el[0]].pb({el[1], x + 1});
                    g[el[1]].pb({el[0], x + 1});
                }
                else {
                    g[el[0]].pb({el[1], x});
                    g[el[1]].pb({el[0], x});
                }
            }
        }
        auto res = dijkstra(g, A);
        if (res[B] > L) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    g.clear();
    g.resize(n);
    forn (i, m) {
        auto el = R[i];
        if (el[2] != 0) {
            g[el[0]].pb({el[1], el[2]});
            g[el[1]].pb({el[0], el[2]});
        }
        else {
            if (i < l) {
                g[el[0]].pb({el[1], x + 1});
                g[el[1]].pb({el[0], x + 1});
            }
            else {
                g[el[0]].pb({el[1], x});
                g[el[1]].pb({el[0], x});
            }
        }
    }
    auto res = dijkstra(g, A);
    if (res[B] != L) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    forn (i, m) {
        auto el = R[i];
        if (el[2] == 0) {
            if (i < l) {
                cout << el[0] << " " << el[1] << " " << x + 1 << "\n";
            }
            else {
                cout << el[0] << " " << el[1] << " " << x + 0 << "\n";
            }
        }
        else {
            cout << el[0] << " " << el[1] << " " << el[2] << "\n";
        }
    }
}