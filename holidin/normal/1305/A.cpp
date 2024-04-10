#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fi first
#define se second
using namespace std;
const int N = 12;
string s[N];
int n, k;
bool use[N][N], useship[N];
int len[N];
int ans = 0;

void solve() {
    int i, j, n;
    cin >> n;
    vector <int> a(n), b(n);
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << "\n";
    for (i = 0; i < n; ++i)
        cout << b[i] << ' ';
    cout << "\n";
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    cin >> test;
    while (test--)
    solve();
}