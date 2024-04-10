#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;



int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);


        auto b = a;
        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        }

        vector<int> r(n);
        for (int i = 0; i < n; i++) r[a[i]] = i;

        vector<char> vis(n);
        vector<vector<int> > ans;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int x = i;
            vector<int> cur;
            while (!vis[x]) {
                cur.push_back(x);
                vis[x] = 1;
                x = a[x];
            }
            sort(cur.begin(), cur.end());
            ans.push_back(cur);
        }
        printf("%d\n", (int)ans.size());
        for (auto v : ans) {
            printf("%d", (int)v.size());
            for (int x : v) printf(" %d", x + 1);
            printf("\n");
        }
        /*

        vector<int> mx(n);
        mx[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mx[i] = max(mx[i + 1], a[i]);
        }

*/
    }


#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}