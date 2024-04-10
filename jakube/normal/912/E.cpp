#include <bits/stdc++.h>
using namespace std;

long long MAX = 1e18;

int n;
vector<int> primes;
vector<long long> f(int start) {
    vector<long long> nums(1, 1);
    for (int i = start; i < n; i+=2) {
        auto next = nums;
        auto p = primes[i];
        for (auto q : nums) {
            while (q <= MAX / p) {
                q *= p;
                next.push_back(q);
            }
        }
        nums = next;
    }

    sort(nums.begin(), nums.end());
    return nums;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    primes.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> primes[i];
    }
    long long k;
    cin >> k;

    if (n == 1) {
        auto num = 1LL;
        for (int i = 1; i < k; i++) {
            num *= primes[0];
        }
        cout << num << '\n';
        return 0;
    }
    
    auto left = f(0);
    auto right = f(1);
    auto count = [&](long long cur) {
        int j = right.size();
        long long cnt = 0;
        for (int i = 0; i < (int)left.size(); i++) {
            while (j > 0 && left[i] > cur / right[j-1]) {
                j--;
            }
            cnt += j;
        }
        return cnt;
    };

    long long L = 0LL; // < k
    long long R = 1e18 + 1; // >= k
    while (L + 1 < R) {
        long long M = (L + R) / 2;
        auto x = count(M);
        if (x < k)
            L = M;
        else
            R = M;
    }
    cout << R << endl;
}