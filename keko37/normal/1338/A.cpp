#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

llint t, n;
llint a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        a[0] = -1e9;
        llint sol = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] < a[i - 1]) sol = max(sol, a[i - 1] -  a[i]);
            a[i] = max(a[i], a[i - 1]);
        }
        llint pot = 1, cnt = 0;
        while (pot <= sol) pot *= 2, cnt++;
        cout << cnt << '\n';
    }
    return 0;
}