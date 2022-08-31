#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1E9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int n = n1 + n2 + n3;
    vector<int> be(n);
    for (int i = 0; i < n1; ++i) {
        int x;
        cin >> x;
        be[--x] = 0;
    }
    for (int i = 0; i < n2; ++i) {
        int x;
        cin >> x;
        be[--x] = 1;
    }
    for (int i = 0; i < n3; ++i) {
        int x;
        cin >> x;
        be[--x] = 2;
    }
    int dp[3] {0, INF, INF};
    for (int i = 0; i < n; ++i) {
        dp[2] = min(dp[0], min(dp[1], dp[2])) + (be[i] != 2);
        dp[1] = min(dp[0], dp[1]) + (be[i] != 1);
        dp[0] += (be[i] != 0);
    }
    cout << min(dp[0], min(dp[1], dp[2])) << endl;
    return 0;
}