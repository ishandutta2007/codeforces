#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void update(vector<int>& a) {
    int n = (int) a.size();
    vector<int> b(n, -1);
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            b[a[i]] = i;
        }
    }
    a = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        update(a);
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[a[i]] = i;
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] != -1) {
                b[i]--;
            }
        }
        update(b);
        int ans = 1;
        vector<int> used(n);
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                used[b[i]] = 1;
                if (pos[b[i]] - s > i) {
                    ans = 0;
                }
            }
        }
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                cnt[max(0, pos[i] - s)]++;
            }
        }
        int was = 0;
        for (int i = 0; i < n; i++) {
            if (i) {
                cnt[i] += cnt[i - 1];
            }
            if (b[i] == -1) {
                ans = ans * 1ll * (cnt[i] - was) % mod;
                was++;
            }
        }
        cout << ans << '\n';
    }
}