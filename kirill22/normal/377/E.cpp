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
#define ll __int128

int id = 0;

struct line {
    int y, k, b;
    int id;
    line() {}
    line(int y, int k, int b, int id) : y(y), k(k), b(b), id(id) {}
};

int get(line A, int x) {
    return (x - A.y) / A.k + A.b;
}

int XX(line A, line B) {
    ld y = A.y, k = A.k, b = A.b;
    ld y2 = B.y, k2 = B.k, b2 = B.b;
    //cout << A.y << " " << A.k << " " << A.b << " " << B.y << " " << B.k << " " << B.b << endl;
    ld ans = ((b2 - y2 / k2) - (b - y / k)) / ((1.0 / k) - (1.0 / k2));
    //cout << ans << endl;
    int res = (int) ans;
    for (int j = max(0ll, res - 15); j <= res + 15; j++) {
        if (get(A, j) >= get(B, j)) {
            //cout << j << endl;
            return j;
            //cout << j << endl;
        }
    }
}

ve<line> st;

void update(line t) {
    while (sz(st) >= 2) {
        line x = st.back();
        st.pop_back();
        line y = st.back();
        if (XX(x, y) < XX(y, t)) {
            st.pb(x);
            break;
        }
    }
    st.pb(t);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, sum;
    cin >> n >> sum;
    ve<pii> a(n);
    forn (i, n) {
        cin >> a[i].se >> a[i].fi;
    }
    sort(all(a), [&] (pii x, pii y) {
        if (x.fi != y.fi) return x.fi < y.fi;
        return x.se > y.se;
    });
    reverse(all(a));
    ve<pii> b;
    forn (i, n) {
        while (sz(b) && b.back().se <= a[i].se) b.pop_back();
        b.pb(a[i]);
    }
    sort(all(b));
    n = sz(b);
    if (n <= 1000) {
        int ans = 1e18;
        ve<int> X(n), Y(n), C(n);
        forn (i, n) {
            X[i] = b[i].se;
            if (b[i].fi == 0) {
                C[i] = 0, Y[i] = 0;
            }
            else {
                C[i] = 1e18;
                forn (ind, i) {
                    int z = (b[i].fi - Y[ind] + X[ind] - 1) / X[ind];
                    if (C[i] > C[ind] + z) {
                        C[i] = C[ind] + z;
                        Y[i] = Y[ind] + z * X[ind] - b[i].fi; 
                    }
                    else if (C[i] == C[ind] + z) {
                        Y[i] = max(Y[i], Y[ind] + z * X[ind] - b[i].fi);
                    }
                }
            }
            if (Y[i] >= sum) ans = min(ans, C[i]);
            else ans = min(ans, C[i] + (sum - Y[i] + X[i] - 1) / X[i]);
        }
        cout << ans;
        return 0;
    }
    int ans = 1e18;
    ve<int> X(n), Y(n), C(n);
    forn (i, n) {
        //cout << i << endl;
        X[i] = b[i].se;
        //cout << b[i].fi << endl;
        if (b[i].fi == 0) {
            C[i] = 0, Y[i] = 0;
        }
        else {
            ld need = b[i].fi;
            while (id + 1 < sz(st) && XX(st[id], st[id + 1]) <= need) id++;
            while (id - 1 >= 0 && XX(st[id - 1], st[id]) > need) id--;
            int ind = st[id].id;
            int z = (b[i].fi - Y[ind] + X[ind] - 1) / X[ind];
            C[i] = C[ind] + z;
            //cout << ind << endl;
            //if (i == 2) cout << XX(st[id - 1], st[id]) << endl;
            Y[i] = Y[ind] + z * X[ind] - b[i].fi;
        }
        //cout << i << endl;
        if (Y[i] >= sum) ans = min(ans, C[i]);
        else ans = min(ans, C[i] + (sum - Y[i] + X[i] - 1) / X[i]);
        //cout << i << endl;
        update(line(Y[i] - X[i] + 1, X[i], C[i], i));
        id = min(id, sz(st) - 1);
        //cout << X[i] << " " << Y[i] << " " << C[i] << endl;
    }
    cout << ans;
}