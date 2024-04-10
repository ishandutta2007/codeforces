#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;

int t, n;
int a[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], a[i] = i - a[i];
        int x = 1, y = 1;
        do {
            x = a[x];
            y = a[a[y]];
        } while (x != y);
        x = 1;
        while (x != y) x = a[x], y = a[y];
        v.clear();
        do {
            v.push_back(x);
            x = a[x];
        } while (x != y);
        cout << v.size() << '\n';
        for (auto x : v) cout << x << " "; cout << '\n';
    }
    return 0;
}