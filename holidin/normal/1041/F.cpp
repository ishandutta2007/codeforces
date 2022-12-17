#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

map <int, int> m;
int a[N], b[N], n1, n2;

int main() {
    int i, j, n1, n2;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n1 >> j;
    for (i = 0; i < n1; ++i)
        cin >> a[i];
    cin >> n2 >> j;
    for (i = 0; i < n2; ++i)
        cin >> b[i];
    int ans = min(2, n1 + n2);
    for (i = 1; i < 1e9; i*=2) {
        m.clear();
        for (j = 0; j < n1; ++j)
            ++m[a[j] % (2 * i)];
        for (j = 0; j < n2; ++j)
            ++m[(b[j] + i) % (2 * i)];
        for (map<int, int> :: iterator it = m.begin(); it != m.end(); ++it)
            ans = max(ans, (*it).second);
    }
    cout << ans;
}