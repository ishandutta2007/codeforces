#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

ll maxSubsequenceSum(vector<ll>& a) {
    int n = a.size();
    if (n == 0) return 0;
    vector<ll> sums(n + 1, 0);
    for (int i = 1; i <= n; i++) sums[i] = sums[i - 1] + a[i - 1];
    vector<ll> maxSums(n, 0);
    maxSums[n - 1] = sums[n];
    for (int i = n - 2; i >= 0; i--) maxSums[i] = max(maxSums[i + 1], sums[i + 1]);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, maxSums[i] - sums[i]);
    }
    return res;

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll maxSum = 0;
        for (int i = 0; i < n; i += 2) maxSum += a[i];

        vector<ll> aEvenOdd(n / 2);
        for (int i = 0; i < n - 1; i += 2) aEvenOdd[i / 2] = a[i + 1] - a[i];
        vector<ll> aOddEven((n - 1) / 2);
        for (int i = 1; i < n - 1; i += 2) aOddEven[i / 2] = a[i] - a[i + 1];
        ll maxSumEvenOdd = maxSubsequenceSum(aEvenOdd);
        ll maxSumOddEven = maxSubsequenceSum(aOddEven);
        ll prevMaxSum = maxSum;
        maxSum = max(maxSum, prevMaxSum + maxSumEvenOdd);
        maxSum = max(maxSum, prevMaxSum + maxSumOddEven);
        cout << maxSum << "\n";
    }
}