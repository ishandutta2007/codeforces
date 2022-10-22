#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

int f(string s) {
    int c = 100, n = s.size();
    if (n >= 3 && s[n - 3] == '.') c = 1;
    int res = 0;
    for (auto c : s) if ('0' <= c && c <= '9') res = (res * 10 + (c - '0'));
    res *= c;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, tmp = "";
    cin >> s;
    int ans = 0;
    for (auto c : s) {
        if ('a' <= c && c <= 'z' && tmp.size()) {
            ans += f(tmp), tmp = "";
        } else tmp += c;
    }   
    ans += f(tmp);
    int c = ans / 100;
    s = to_string(c);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (n >= 3 && i % 3 == (n - 3) % 3 && i != 0) cout << ".";
        cout << s[i];
    }
    if (ans % 100 != 0) {
        if (ans % 100 > 9) {
            cout << "." << ans % 100;
        }
        else {
            cout << ".0" << ans % 100;
        }
    }
}