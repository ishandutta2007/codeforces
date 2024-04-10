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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ve<string> a = {"unlock", "blue"};
    while (n--) {
        string s;
        cin >> s;
        a.pb(s);
    }
    a.pb("lock");
    n = sz(a);
    set<int> tmp;
    set<pii> st;
    string pr;
    forn (i, n) {
        if (a[i].back() == 'k') tmp.insert(i), pr = a[i];
        else {
            if (pr == "lock") continue;
            if (i > 0 && a[i - 1].back() != 'k') {
                auto el = *st.rbegin();
                st.erase(el);
                st.insert({el.fi, el.se + 1});
            }
            else {
                st.insert({i, i});
            }
        }
    }
    cout << a[(*st.rbegin()).se] << '\n';
    int q;
    cin >> q;
    while (q--) {
        int pos;
        string s;
        cin >> pos >> s;
        pos++;
        tmp.erase(pos);
        auto it = tmp.lower_bound(pos);
        int r = *it;
        it--;
        int l = *it;
        if (a[pos] == "lock" && s == "lock") {
            tmp.insert(pos);
        }
        else if (a[pos] == "unlock" && s == "unlock") {
            tmp.insert(pos);
        }
        else if (a[pos] == "lock" && s == "unlock") {
            tmp.insert(pos);
            if (pos + 1 <= r - 1) st.insert({pos + 1, r - 1});
        }
        else if (a[pos] == "unlock" && s == "lock") {
            tmp.insert(pos);
            if (pos + 1 <= r - 1) st.erase({pos + 1, r - 1});
        }
        else if (a[pos] == "unlock") {
            if (a[l] == "lock") {
                if (pos + 1 <= r - 1) st.erase({pos + 1, r - 1});
            }
            else {
                if (l + 1 <= pos - 1) st.erase({l + 1, pos - 1});
                if (pos + 1 <= r - 1) st.erase({pos + 1, r - 1});
                if (l + 1 <= r - 1) st.insert({l + 1, r - 1});
            }
        }
        else if (a[pos] == "lock") {
            if (a[l] == "lock") {
            }
            else {
                if (l + 1 <= pos - 1) st.erase({l + 1, pos - 1});
                if (l + 1 <= r - 1) st.insert({l + 1, r - 1});
            }
        }
        else if (s == "lock") {
            tmp.insert(pos);
            if (a[l] == "lock") {
            }
            else {
                if (l + 1 <= r - 1) st.erase({l + 1, r - 1});
                if (l + 1 <= pos - 1) st.insert({l + 1, pos - 1});
            }
        }
        else if (s == "unlock") {
            tmp.insert(pos);
            if (a[l] == "lock") {
                if (pos + 1 <= r - 1) st.insert({pos + 1, r - 1});
            }
            else {
                if (l + 1 <= r - 1) st.erase({l + 1, r - 1});
                if (l + 1 <= pos - 1) st.insert({l + 1, pos - 1});
                if (pos + 1 <= r - 1) st.insert({pos + 1, r - 1});
            }
        }
        a[pos] = s;
        cout << a[(*st.rbegin()).se] << '\n';
        //debug(st, tmp);
    }
}