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
    return;
    for (int i = 0; i < k / 2; ++i)
        swap(s[i], s[k - i - 1]);
    for (int i = 0; i < k; ++i)
    if (s[i] == '0')
        s[i] = '1';
    else
        s[i] = '0';
}


char f(char c, bool rev) {
    if (rev)
        if (c == '0')
            return '1';
        else
            return '0';
    else
        return c;
}

void solve() {
    int n, i, j, k;
    string a, b;
    cin >> n >> a >> b;
    ans.clear();
    int l = 0, r = n - 1;
    bool rev = false;
    bool inv = false;
    for (int i = n - 1; i >= 0; --i) {
        if ((!rev && f(a[l], inv) == b[i]) || (rev && f(a[r], inv) == b[i]))
            operate(a, 1);
        operate(a, i + 1);
        if (rev)
            --r;
        else
            ++l;
        inv ^= 1;
        rev ^= 1;
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