#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int a[N];
int b[N];
int tmp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++) b[i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int k = i - a[i];
            if (k < 0) k += n;
            b[k]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (b[i] * 3 + 3 >= n) {
                for (int j = 1; j <= n; j++) {
                    int pos = j - i;
                    if (pos <= 0) pos += n;
                    tmp[pos] = a[j];
                }
                int cnt = 0;

                for (int k = 1; k <= n; k++) {
                    if (tmp[k] != 0) {
                        cnt++;
                        int now = k;
                        while (now) {
                            int nxt = tmp[now];
                            tmp[now] = 0;
                            now = nxt;
                        }
                    }
                }
                if (n - cnt <= m) ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << ' ';
        for (auto x:ans) cout << x << ' ';
        cout << endl;
    }
}