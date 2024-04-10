#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

vector <int> v;
int b[N];

int main() {
    int i, j, n, k, m, x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (i = 1; i <= n; ++i)
        cin >> b[i];
    for (i = 2; i <= n; ++i)
        v.push_back(b[i] - b[i - 1]);
    sort(v.begin(), v.end());
    int ans = n;
    for (i = 0; i < v.size() - k + 1; ++i)
        ans += v[i] - 1;
    cout << ans;
}