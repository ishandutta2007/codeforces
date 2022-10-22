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

const int mod = 998244353;
vector<int> d = {1, 2, 3, 5, 9, 17};

ve<ve<int>> dp;

void calc(int x, ve<int> a) {
    if (x == 0) {
        dp.pb(a);
        return;
    }
    ve<int> d;
    forn (i, sz(a)) if (a[i] == x) d.pb(i);
    forn (msk, (1 << (sz(d) / 2))) {
        ve<int> b = a;
        for (int i = 0; i < sz(d); i += 2) {
            if (msk >> (i / 2) & 1) {
                b[d[i]]--;
            } else {
                b[d[i + 1]]--;
            }
        }
        calc(x - 1, b);
    }
}

int get(ve<int>& a) {
    int res = 0;
    forn (i, sz(a)) {
        res = (res + (i + 1) * d[a[i]]) % mod;
    }
    return res;
}

void print(ve<int> ans) {
    for (auto x : ans) {
        if (x == 0) cout << 1 << " ";
        else cout << (1 << (x - 1)) + 1 << " ";
    }
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, A, h;
    cin >> k >> A >> h;
    for (auto& x : d) {
        int res = 1;
        forn (i, x) res = res * A % mod;
        x = res;
    }
    ve<int> ans((1 << min(k, 4ll)), min(k, 4ll));
    calc(min(k, 4ll), ans);
    if (k <= 4) {
        for (auto el : dp) {
            if (get(el) == h) {
                print(el);
            }
        }
        cout << -1;
        return 0;
    }
    map<int, int> usd;
    for (auto el2 : dp) {
        ve<int> el((1 << k), k);
        for (int i = 1; i < (1 << k); i += 2) el[i] = el2[i / 2];
        ve<int> upd;
        for (int i = 0; i < sz(el); i += 2) {
            int res = ((i + 1) * d[el[i]] + (i + 2) * d[el[i + 1]]) % mod;
            int res2 = ((i + 1) * d[el[i + 1]] + (i + 2) * d[el[i]]) % mod;
            upd.pb((res2 - res + mod) % mod); 
        }
        int p = get(el);
        usd.clear();
        forn (msk, (1 << 8)) {
            int res = 0;
            forn (j, 8) if (msk >> j & 1) {
                res = (res + upd[j]) % mod;
            }
            usd[res] = msk;
        }
        forn (msk, (1 << 8)) {
            int res = 0;
            forn (j, 8) if (msk >> j & 1) {
                res = (res + upd[j + 8]) % mod;
            }
            int need = (h - p - res + mod + mod) % mod;
            if (usd.find(need) != usd.end()) {
                forn (j, 8) if (msk >> j & 1) {
                    swap(el[(j + 8) * 2], el[(j + 8) * 2 + 1]);
                }
                forn (j, 8) if (usd[need] >> j & 1) {
                    swap(el[j * 2], el[j * 2 + 1]);
                }
                assert(get(el) == h);
                print(el);
            }
        }
    }
    cout << -1;
}