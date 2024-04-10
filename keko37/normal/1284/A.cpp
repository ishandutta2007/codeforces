#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 24;

int n, m, q;
string s[MAXN], t[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << s[(x - 1) % n] + t[(x - 1) % m] << endl;
    }
    return 0;
}