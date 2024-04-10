#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long a[200009];
vector<long long> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; long long k, x; cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = n;
    for (int i = 1; i < n; i++) {
        long long t = a[i + 1] - a[i];
        if (t <= x) ans--;
        else v.push_back((t - 1) / x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (k < v[i]) break;
        k -= v[i]; ans--;
    }
    cout << ans << '\n';
    return 0;
}