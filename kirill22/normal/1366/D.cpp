#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

vector<int> eratosfen(int n) {
    vector<int> d(n + 1, 1);
    vector<int> prime;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 1) {
            d[i] = i;
            prime.push_back(i);
        }
        for (auto x : prime) {
            if (x * i > n || x > d[i]) break;
            d[x * i] = x;
        }
    }
    return d;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> c = eratosfen(10000000 + 1);
    int n;
    cin >> n;
    vector<int> a(n), ans(n, -1), ans2(n, -1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (c[a[i]] == a[i]) continue;
        int x = c[a[i]];
        int tmp = 1;
        while (a[i] % x == 0) {
            tmp *= x;
            a[i] /= x;
        }
        if (a[i] == 1) continue;
        ans[i] = tmp;
        ans2[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    } cout << endl;
    for (int i = 0; i < n; i++) {
        cout << ans2[i] << " ";
    } cout << endl;
}