#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 4e4 + 22;
vector<int> ok;
int dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < N; i++) {
        string s = to_string(i);
        string t = s;
        reverse(s.begin(), s.end());
        if (t == s) {
            ok.push_back(i);
        }
    }
    dp[0] = 1;
    for (auto j : ok) {
        for (int i = 1; i < N; i++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}