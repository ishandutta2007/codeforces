#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, sol, a[MAXN], b[MAXN], pos[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int mn = MAXN;
    for (int i = n; i >= 1; i--) {
        b[i] = pos[b[i]];
        if (b[i] > mn) sol++;
        mn = min(mn, b[i]);
    }
    cout << sol;
    return 0;
}