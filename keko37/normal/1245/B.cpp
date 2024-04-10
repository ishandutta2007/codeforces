#include<bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int t, n, a, b, c;
string s;
char sol[MAXN];

bool check () {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S' && sol[i] == 'R') cnt++;
        if (s[i] == 'R' && sol[i] == 'P') cnt++;
        if (s[i] == 'P' && sol[i] == 'S') cnt++;
    }
    return cnt * 2 >= n;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> c >> s;
        for (int i = 0; i < n; i++) {
            sol[i] = '.';
            if (s[i] == 'S' && a > 0) sol[i] = 'R', a--;
            if (s[i] == 'R' && b > 0) sol[i] = 'P', b--;
            if (s[i] == 'P' && c > 0) sol[i] = 'S', c--;
        }
        for (int i = 0; i < n; i++) {
            if (sol[i] != '.') continue;
            if (a > 0) {
                sol[i] = 'R', a--;
            } else if (b > 0) {
                sol[i] = 'P', b--;
            } else {
                sol[i] = 'S', c--;
            }
        }
        if (check()) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) cout << sol[i]; cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}