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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    vector<int> b;
    int x = a[0], s = a[0], bonus = 0;
    for (int i = 1; i < n; i++) {
        int p = a[i] - x;
        s += a[i];
        if (p < 2 || i == 1) {
            if (p % 2 == 0) b.pb(i);
            else bonus++;
        }
        else {
            while (p >= 2) {
                if (b.size() == 0) {
                    p %= (i + 1);
                    int k = max(0ll, p - 1);
                    if (k) {
                        p -= k;
                        b.pb(k);
                        bonus -= (i - k + 1);
                    }
                    break;
                }
                if (b.size() > 0 && b.back() == i - 1) {
                    b.pop_back();
                    p -= 2;
                    bonus += 2;
                    continue;
                }
                else {
                    int v = b.back();
                    int cnt = (i - 1) - v;
                    if (p - cnt >= 1) {
                        p -= cnt;
                        bonus += cnt;
                        b.pop_back();
                        b.pb(i - 1);
                    }
                    else {
                        int k = min(cnt, p - 1);
                        p -= k;
                        bonus += k;
                        b.pop_back();
                        b.pb(v + k);
                        break;
                    }
                }
            }
            if (p % 2 == 0) b.pb(i);
            else bonus++;
        }
        int l = i + 1;
        int st = (s - bonus) / l;
        x = st + (i - b.size());
        bonus += (i - b.size());
    }
    vector<int> ans(n);
    ans[n - 1] = x;
    int tmp = (int) b.size() - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (tmp >= 0 && b[tmp] == i + 1) {
            ans[i] = ans[i + 1];
            tmp--;
        }
        else ans[i] = ans[i + 1] - 1;
    }
    for (auto el : ans) cout << el << " ";
}