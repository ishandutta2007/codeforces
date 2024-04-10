#include<bits/stdc++.h>

using namespace std;

template<typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& c) {
    string res = "'";
    res += c;
    return res + "'";
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template<typename A>
string to_string(A a) {
    string res = "{";
    int f = 0;
    for (const auto& x : a) {
        if (f) {
            res += ", ";
        }
        f = 1;
        res += to_string(x);
    }
    return res + "}";
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "{" + to_string(p.first) + ", " + to_string(p.second) + "}";
}

void debug_out() { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
    cerr << " " << to_string(h);
    debug_out(t...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << ":] ", debug_out(__VA_ARGS__)
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define ld long double
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

void solve() {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto c : s) {
        cnt[c]++;
    }
    int i = 0;
    while (i < sz(s)) {
        if (cnt[s[i]] >= 2) {
            cnt[s[i]]--;
            i++;
        } else break;
    }
    for (int j = i; j < sz(s); j++) cout << s[j];
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}