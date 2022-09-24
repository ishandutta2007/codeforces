#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 19;
const int MOD = (int)1e9 + 7;



int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (cin >> n) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < n; i++) {
            bool f = 0;
            for (int j = 0; j < i; j++) if (a[j] == a[i]) f = 1;
            string res = f ? "YES" : "NO";
            cout << res << endl;
        }
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}