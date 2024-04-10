#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint n, sol, sum;
llint a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i % 2 == 1) sum += a[i];
    }
    a[n + 1] = a[1];
    sol = sum;
    for (int i = 1; i <= n; i++) {
        int pos = 2 * i - 1;
        if (pos > n) pos -= n;
        sum -= a[pos];
        sum += a[pos + 1];
        sol = max(sol, sum);
    }
    cout << sol;
    return 0;
}