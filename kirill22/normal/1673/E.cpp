#include<bits/stdc++.h>

using namespace std;

const int N = 1 << 20;
int dp[N];
map<pair<int, int>, int> cost;

int CNK(int n, int k) {
    int res = dp[n] - dp[k] - dp[n - k];
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < N; i++) {
        int x = i;
        while (x % 2 == 0) {
            dp[i]++;
            x /= 2;
        }
        dp[i] += dp[i - 1];
    }
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string ans(N, '0');
    auto upd = [&] (int x) {
        if (x < N) {
            if (ans[x] == '0') {
                ans[x] = '1';
            } else {
                ans[x] = '0';
            }
        }
    };
    for (int i = 0; i < n; i++) {
        int tmp = a[i];
        for (int j = i; j < n; j++) {
            if (j > i) {
                if (a[j] > 20 || tmp * 1ll * (1ll << a[j]) >= N) {
                    break;
                }
                tmp *= (1ll << a[j]);
            }
            int need = j - i, cnt = 0;
            if (j + 1 < n) {
                need++;
                cnt++;
            }
            if (i) {
                need++;
                cnt++;
            }
            if (cnt >= k) {
                //cout << i << endl;
                if ((n - 1) - need == 0) {
                    upd(tmp);
                }
            } else if ((n - 1) - need >= k - cnt){
                int A = (n - 1) - need, B = k - cnt;
                int res = 0;
                if (cost.find({A, B}) != cost.end()) {
                    res = cost[{A, B}];
                } else {
                    for (int C = B; C <= A; C++) {
                        if (CNK(A, C) == 0) {
                            res ^= 1;
                        }
                    }
                    cost[{A, B}] = res;
                }
                //cout << i << "F" << endl;
                if (res) {
                    upd(tmp);
                }
            }
        }
    }
    while ((int) ans.size() > 1 && ans.back() == '0') {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}