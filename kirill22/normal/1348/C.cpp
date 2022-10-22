#include<bits/stdc++.h>

using namespace std;

#define int long long

string f(string a, string b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] < b[i]) return b;
        if (b[i] < a[i]) return a;
    }
    if (a.size() < b.size()) return b;
    return a;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> a(k);
    for (int i = 0; i < k; i++) {
        a[i] += s[i];
    }
    map<char, int> b;
    char mx = 'a';
    for (int i = k; i < n; i++) b[s[i]]++;
    for (int i = k; i < n; i++) mx = max(mx, s[i]);
    if (a[0] != a[k - 1]) {
        cout << a[k - 1] << endl;
        return;
    }
    int tmp = k;
    for (auto el : b) {
        int res = el.second;
        if (el.first == mx) {
            if (tmp == 1) {
                for (int i = 0; i < res; i++) a[0] += el.first;
            }
            else {
                for (int i = 0; i < (res + tmp - 1) / tmp; i++) a[0] += el.first;
            }
        }
        else {
            while (res) {a[0] += el.first; res--;}
            tmp = 1;
        }
    }
    cout << a[0] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q; while (q--) solve();
}