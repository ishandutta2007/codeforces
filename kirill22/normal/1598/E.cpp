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

const int N = 1000;
int a[N][N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int ans = n * m;
    forn (i, n) forn (j, m) {
        ans += min(m - 1 - j, n - i);
        ans += min(m - 1 - j, n - i - 1);
        ans += min(m - j, n - i - 1);
        ans += min(m - j - 1, n - i - 1);
    }
    //cout << ans << endl;
    forn (T, q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int cl = 0, cr = 0, vx, vy;
        {
            vx = x, vy = y;
            while (1) {
                cr++;
                if (cr % 2 == 1) vx++;
                else vy++;
                if (vx >= n || vy >= m || a[vx][vy] == 1) break;
            }
            vx = x, vy = y;
            while (1) {
                cl++;
                if (cl % 2 == 1) vy--;
                else vx--;
                if (vx < 0 || vy < 0 || a[vx][vy] == 1) break;
            }
        }
        int cll = 0, crr = 0;
        {
            vx = x, vy = y;
            while (1) {
                crr++;
                if (crr % 2 == 0) vx++;
                else vy++;
                if (vx >= n || vy >= m || a[vx][vy] == 1) break;
            }
            vx = x, vy = y;
            while (1) {
                cll++;
                if (cll % 2 == 0) vy--;
                else vx--;
                if (vx < 0 || vy < 0 || a[vx][vy] == 1) break;
            }
        }
        int res = cll * crr + cl * cr - 1;
        //debug(cll, crr, cl, cr);
        if (a[x][y] == 0) {
            ans -= res;
        } else {
            ans += res;
        }
        a[x][y] ^= 1;
        cout << ans << '\n';
    }
}