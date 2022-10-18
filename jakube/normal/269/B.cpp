#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    double tmp;
    for (int i = 0; i < n; i++) cin >> v[i] >> tmp;

    vector<int> dp(m+1, 0);
    for (int i = 0; i < n; i++) {
        int ma = 0;
        for (int j = 0; j < m+1; j++) {
            ma = max(ma, dp[j]);
            if (v[i] == j)
                dp[j] = 1 + ma;
        }
    }
    cout << n - *max_element(dp.begin(), dp.end()) << endl;
}