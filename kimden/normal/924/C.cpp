#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100105], must[100105];
ll ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        must[i] = max(must[i - 1], a[i] + 1);
    }
    for (int i = n - 1; i >= 1; --i)
        must[i] = max(must[i], must[i + 1] - 1);
    for (int i = 2; i <= n; ++i)
        ans += must[i] - 1 - a[i];
    cout << ans << endl;
}