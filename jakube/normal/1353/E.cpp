#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int rem = 0;
    for (int i = 0; i < k; i++) {
        int best_balance = 0;
        int cur_balance = 0;
        for (int j = i; j < n; j+=k) {
            cur_balance += (s[j] == '1') ? 1 : -1;
            if (cur_balance < 0) {
                cur_balance = 0;
            }
            if (cur_balance > best_balance) {
                best_balance = cur_balance;
            }
        }
        rem = max(rem, best_balance);
    }
    cout << count(s.begin(), s.end(), '1') - rem << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
}