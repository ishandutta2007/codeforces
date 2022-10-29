#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int a[2000];
bool vis[2000];

bool cmp(int a, int b) { return a > b; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof vis);
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n, cmp);
        vis[1] = 1;
        vector<int> ans;
        ans.push_back(a[1]);
        int g = a[1];
        for (int i = 1; i < n; i++) {
            int mmax = 0;
            int p = 0;
            for (int j = 1; j <= n; j++) {
                if (vis[j]) continue;
                int gg = gcd(g, a[j]);
                if (gg > mmax) {
                    mmax = gg;
                    p = j;
                }
            }
            vis[p] = 1;
            ans.push_back(a[p]);
            g = mmax;
        }
        for (auto x : ans) cout << x << ' ';
        cout << endl;
    }
}