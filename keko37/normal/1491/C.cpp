#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 5005;

int t, n;
llint a[MAXN], val[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) val[i] = 0;
        llint sol = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int lo = i + 2, hi = min((llint) n, i + a[i]);
            for (int j = lo; j <= hi; j++) {
                val[j]++;
            }
            if (a[i] - 1 >= val[i]) {
                sol += a[i] - 1 - val[i];
            } else {
                val[i + 1] += val[i] - (a[i] - 1);
            }
        }
        cout << sol << '\n';
    }
    return 0;
}