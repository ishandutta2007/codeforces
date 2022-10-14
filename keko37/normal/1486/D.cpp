#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n, k;
int a[MAXN], p[MAXN];

bool check (int x) {
    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + (a[i] >= x) * 2 - 1;
        if (i >= k) {
            mn = min(mn, p[i - k]);
            if (mn < p[i]) return 1;
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo;
    return 0;
}