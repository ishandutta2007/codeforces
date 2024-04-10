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
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int> b;
    set<int> c;
    sort(all(a));
    for (auto x : a) c.insert(x);
    for (int i = 1; i < n; i++) b.insert(a[i] - a[i - 1]);
    if (b.size() == 0) {
        cout << 0 << '\n';
    }
    else cout << *c.rbegin() - *c.begin() - *b.rbegin() << '\n';
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            auto it = c.lower_bound(x);
            int y = -1, z = -1;
            if (it != c.begin()) {
                auto it2 = it;
                it2--;
                y = *it2;
            }
            it++;
            if (it != c.end()) {
                z = *it;
            }
            c.erase(x);
            if (y == -1 && z == -1) {
                cout << 0 << '\n';
                continue;
            }
            if (y != -1 && z != -1) {
                b.erase(b.find(x - y));
                b.erase(b.find(z - x));
                b.insert(z - y);
            }
            else if (y != -1) {
                b.erase(b.find(x - y));
            }
            else if (z != -1) {
                b.erase(b.find(z - x));
            }
            if (b.size() == 0) {
                cout << 0 << '\n';
            }
            else cout << *c.rbegin() - *c.begin() - *b.rbegin() << '\n';
        }
        else {
            c.insert(x);
            auto it = c.lower_bound(x);
            int y = -1, z = -1;
            if (it != c.begin()) {
                auto it2 = it;
                it2--;
                y = *it2;
            }
            it++;
            if (it != c.end()) {
                z = *it;
            }
            if (y == -1 && z == -1) {
                cout << 0 << '\n';
                continue;
            }
            if (y != -1 && z != -1) {
                b.insert(x - y);
                b.insert(z - x);
                b.erase(b.find(z - y));
            }
            else if (y != -1) {
                b.insert(x - y);
            }
            else if (z != -1) {
                b.insert(z - x);
            }
            if (b.size() == 0) {
                cout << 0 << '\n';
            }
            else cout << *c.rbegin() - *c.begin() - *b.rbegin() << '\n';
        }
    }
}