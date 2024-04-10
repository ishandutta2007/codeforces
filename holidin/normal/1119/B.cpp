#include <bits/stdc++.h>
using namespace std;
const int N  = 5e5 + 1;
vector <int> v;
int a[N];
int main() {
    int i, j, k, n, m, b, s;
    long long h, h1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> h;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
        sort(v.begin(), v.end());
        h1 = h;
        for (int i = v.size() - 1; i >= 0; i -= 2)
            h1 -= v[i];
        if (h1 < 0) {
            cout << i - 1;
            exit(0);
        }
    }
    cout << n;
}