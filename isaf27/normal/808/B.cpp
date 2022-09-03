#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const int BIG = 1e9;
const ll INF = 1e18;
const int M = 2e5 + 1;
const int L = 18;

int n, k;
ll a[M], pr[M];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pr[0] = 0;
    for (int i = 0; i < n; i++)
        pr[i + 1] = pr[i] + a[i];
    ll s = 0;
    for (int i = 0; i <= n - k; i++)
        s += pr[i + k] - pr[i];
    cout << fixed << setprecision(20);
    cout << (ld)s / (n - k + 1);
    return 0;
}