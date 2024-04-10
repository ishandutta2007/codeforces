// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[200005];
vector<int> ops;
string s, sgn;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    cin >> s;

    sort(a, a+n);
    sgn = s;
    sgn[n-1] = s[n-1];
    for (int i=n-2; i>=0; i--) {
        sgn[i] = sgn[i+1] ^ 'L' ^ 'R';
    }

    int u = 0, v = n-1;
    for (int i=n-1; i>=1; i--) {
        char t = s[i-1];
        if (t == sgn[v]) {
            ops.push_back(u++);
        } else {
            ops.push_back(v--);
        }
    }
    ops.push_back(u);

    reverse(begin(ops), end(ops));

    for (int i : ops) {
        cout << a[i] << ' ' << sgn[i] << "\n";
    }
}