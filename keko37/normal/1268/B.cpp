#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 300005;

llint n, sum, cnt;
llint a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (i % 2 == 0) cnt += a[i] / 2; else cnt += (a[i] + 1) / 2;
    }
    cout << min(cnt, sum - cnt);
    return 0;
}