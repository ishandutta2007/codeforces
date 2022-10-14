#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint n, m, sol;
llint a[MAXN], p[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        p[i] = a[i];
        if (i - m >= 0) p[i] += p[i - m];
        sol += p[i];
        cout << sol << " ";
    }
    return 0;
}