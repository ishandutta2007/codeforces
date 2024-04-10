#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
string s, tmp, r = "abacaba";

bool moze (int pos) {
    for (int i = 0; i < 7; i++) {
        if (s[pos + i] == '?') continue;
        if (s[pos + i] != r[i]) return 0;
    }
    return 1;
}

void postavi (int pos) {
    tmp = s;
    for (int i = 0; i < 7; i++) {
        tmp[pos + i] = r[i];
    }
    for (int i = 0; i < n; i++) {
        if (tmp[i] == '?') tmp[i] = 'x';
    }
}

int broji () {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tmp.substr(i, 7) == r) cnt++;
    }
    return cnt;
}

void solve () {
    for (int i = 0; i + 6 < n; i++) {
        if (moze(i)) {
            postavi(i);
            int br = broji();
            if (br == 1) {
                cout << "Yes\n";
                cout << tmp << '\n';
                return;
            }
        }
    }
    cout << "No\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        solve();
    }
    return 0;
}