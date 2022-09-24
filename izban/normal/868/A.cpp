#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 17;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    string s;
    while (cin >> s) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool f = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                string t = a[i] + a[j];
                if (t.find(s) != -1) {
                    f = 1;
                }
            }
        }
        string ans = f ? "YES" : "NO";
        cout << ans << endl;
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}