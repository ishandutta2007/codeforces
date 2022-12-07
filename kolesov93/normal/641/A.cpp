#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n;    
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int x = 0;
    vector<int> was(n, false);
    while (1) {
        if (x < 0 || x >= n) {
            puts("FINITE");
            return 0;
        }
        if (was[x]) {
            puts("INFINITE");
            return 0;
        }
        was[x] = 1;
        if (s[x] == '<') {
            x -= a[x];
        } else {
            x += a[x];
        }
    }

    return 0;
}