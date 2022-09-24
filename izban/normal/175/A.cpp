#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = -1;


int f(string s) {
    if (s.length() > 7) return -1;
    if (s.length() > 1 && s[0] == '0') return -1;
    int x = 0;
    for (int i = 0; i < (int)s.length(); i++) x = 10 * x + (s[i] - '0');
    if (x > 1000000) return -1;
    return x;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    string s;
    while (cin >> s) {
        int n = s.length();
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (i + j + k != n) continue;
                    string a = s.substr(0, i);
                    string b = s.substr(i, j);
                    string c = s.substr(i + j, k);


                    int x = f(a);
                    int y = f(b);
                    int z = f(c);
                    if (x != -1 && y != -1 && z != -1) {
                        ans = max(ans, x + y + z);
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}