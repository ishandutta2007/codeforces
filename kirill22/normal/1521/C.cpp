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

int n;
ve<int> resa;

int ask(int i, int j) {
    cout << "? 2 " << i + 1 << " " << j + 1 << " " << 1 << endl;
    //return min(resa[i], max(2ll, resa[j]));
    int res; cin >> res; return res;
}

int ask2(int i, int j) {
    cout << "? 1 " << i + 1 << " " << j + 1 << " " << n - 1 << endl;
    //return max(min(n - 1, resa[i]), resa[j]);
    int res; cin >> res; return res;
}

mt19937 gen(time(0));

void solve() {
    cin >> n;
    if (0) {
        resa.clear();
        resa.resize(n);
        forn (i, n) cin >> resa[i];
    }
    ve<int> ans(n);
    for (int i = 0; i < n; i += 2) {
        int res = ask(i, i + 1); if (res == 2) res = ask(i + 1, i);
        int res2 = ask2(i, i + 1); if (res2 == n - 1) res2 = ask2(i +  1, i);
        cout << "? 2" << " " << i + 1 << " " << i + 2 << " " << res << endl;
        int f;
        cin >> f;
        //f = min(max(res, resa[i]), max(res + 1, resa[i + 1]));
        if (f == res) {
            ans[i] = res, ans[i + 1] = res2;
        }
        else {
            ans[i] = res2, ans[i + 1] = res;
        }
        if (i == n - 3) {
            i--;
        }
    }
    cout << "! ";
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    if (1) cin >> test;
    forn (WORLD_OF_TANKS, test) {
        solve();
    }
}