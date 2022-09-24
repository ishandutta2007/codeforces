#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = (int)1e9;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> s(n), g(n);
        for (int i = 0; i < n; i++) scanf("%d%d", &s[i], &g[i]);


        //int id = 0;
        //for (int i = 1; i < n; i++) if (s[i] + g[i] < s[id] + g[id]) i = id;

        vector<int> mx(n, INF);
        mx[0] = s[0] + g[0];
        for (int i = 1; i < n; i++) {
            mx[i] = min(mx[i - 1] + 1, s[i] + g[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            mx[i] = min(mx[i + 1] + 1, mx[i]);
        } 

        bool ok = 1;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ok &= mx[i] >= s[i];
            sum += mx[i] - s[i];
        }

        if (!ok) cout << -1 << endl;
        else {
            printf("%lld\n", sum);
            for (int i = 0; i < n; i++) printf("%d%c", mx[i], " \n"[i + 1 == n]);
        }
    }
    
    return 0;
}