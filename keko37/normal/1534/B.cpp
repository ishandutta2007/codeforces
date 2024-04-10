#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 400005;

llint t, n;
llint a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        llint sum = 0;
        a[0] = a[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n + 1; i++) {
            sum += abs(a[i] - a[i - 1]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                llint d = a[i] - max(a[i - 1], a[i + 1]);
                a[i] -= d;
                sum -= d;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}