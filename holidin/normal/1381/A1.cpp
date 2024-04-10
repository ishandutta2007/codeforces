#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;

vector <int> ans;

void operate(string& s, int k) {
    ans.push_back(k);
    for (int i = 0; i < k / 2; ++i)
        swap(s[i], s[k - i - 1]);
    for (int i = 0; i < k; ++i)
    if (s[i] == '0')
        s[i] = '1';
    else
        s[i] = '0';
}


void solve() {
    int n, i, j, k;
    string a, b;
    cin >> n >> a >> b;
    ans.clear();
    for (int i = n - 1; i >= 0; --i) {
        if (b[i] == a[0])
            operate(a, 1);
        operate(a, i + 1);
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << ' ';
    cout << "\n";
}

signed main() {
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test = 0;
    cin >> test;
    for (int i = 0; i < test; ++i)
    solve();
}