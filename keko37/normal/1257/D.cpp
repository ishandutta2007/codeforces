#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int t, n, m;
int a[MAXN], p[MAXN], s[MAXN], mx[MAXN];

int f (int curr) {
    int cnt = 0, pw = 0;
    while (curr < n) {
        pw = max(pw, a[curr]);
        cnt++;
        if (mx[cnt] < pw) return curr;
        curr++;
    }
    return curr;
}

int main () {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx[i + 1] = 0;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> p[i] >> s[i];
            mx[s[i]] = max(mx[s[i]], p[i]);
        }
        for (int i = n - 1; i >= 1; i--) {
            mx[i] = max(mx[i], mx[i + 1]);
        }
        int sol = 0, curr = 0;
        do {
            sol++;
            int novi = f(curr);
            if (curr == novi) break;
            curr = novi;
        } while (curr < n);
        if (curr == n) cout << sol << '\n'; else cout << "-1\n";
    }
    return 0;
}