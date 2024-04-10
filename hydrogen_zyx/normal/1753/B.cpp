#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

int a[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    for (int i = 1; i < x; i++) {
        int e = cnt[i] / (i + 1);
        cnt[i] -= e * (i + 1);
        cnt[i + 1] += e;
    }
    bool ok = 1;
    for (int i = 1; i < x; i++) if (cnt[i]) ok = 0;
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}