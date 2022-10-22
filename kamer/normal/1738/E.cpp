#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);

    int N = 100005;
    vector<ll> fact(N, 1);
    vector<ll> inv(N, 1);
    vector<ll> inv_fact(N, 1);
    vector<ll> pow_2(N, 1);
    pow_2[1] = 2;

    for (ll i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        inv_fact[i] = (inv_fact[i - 1] * inv[i]) % MOD;
        pow_2[i] = (pow_2[i - 1] * 2) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        vector<int> left_0;
        vector<int> right_0;
        
        int left_index = 0, right_index = n - 1;
        ll left_sum = 0, right_sum = 0;
        bool has_middle;
        while (left_index <= right_index) {
            int left_zero = 0;
            while (a[left_index] == 0 && left_index < n) {
                left_zero++;
                left_index++;
            }

            int right_zero = 0;
            while (a[right_index] == 0 && right_index >= 0) {
                right_zero++;
                right_index--;
            }

            left_0.emplace_back(left_zero);
            right_0.emplace_back(right_zero);

            if (left_index > right_index) {
                has_middle = false;
                break;
            }

            if (left_index == right_index) {
                has_middle = true;
                break;
            }

            left_sum += a[left_index];
            right_sum += a[right_index];

            left_index++;
            right_index--;

            bool finito = false;
            while (left_sum != right_sum) {
                if (left_index > right_index) {
                    finito = true;
                    break;
                }

                if (left_sum < right_sum) {
                    left_sum += a[left_index];
                    left_index++;
                } else {
                   right_sum += a[right_index];
                   right_index--;
                }
            }

            if (finito) {
                has_middle = true;
                break;
            }

            if (left_index > right_index) {
                left_0.emplace_back(0);
                right_0.emplace_back(0);
                has_middle = false;
                break;
            }
        }

        /*
        cout << "has middle : " << has_middle << "\n";
        for (auto l : left_0) {
            cout << l << " ";
        }
        cout << "\n";
        for (auto r : right_0) {
            cout << r << " ";
        }
        cout << "\n";
        */

        if (left_0.empty()) {
            cout << "1\n";
            continue;
        }

        for (int i = 1; i < left_0.size(); i++) {
            left_0[i]++;
            right_0[i]++;
        }
        
        ll result = 1;
        for (int i = 0; i < left_0.size() - 1; i++) {
            ll term = 0;
            ll l = left_0[i], r = right_0[i];
            for (int k = 0; k <= min(l, r); k++) {
                term = (term + fact[l] * inv_fact[k] % MOD * inv_fact[l - k] % MOD * fact[r] % MOD * inv_fact[k] % MOD * inv_fact[r - k] % MOD) % MOD;
            }
            result = (result * term) % MOD;
        }

        if (has_middle) {
            ll term = 0;
            ll l = left_0[left_0.size() - 1], r = right_0[right_0.size() - 1];
            for (int k = 0; k <= min(l, r); k++) {
                term = (term + fact[l] * inv_fact[k] % MOD * inv_fact[l - k] % MOD * fact[r] % MOD * inv_fact[k] % MOD * inv_fact[r - k] % MOD) % MOD;
            }
            result = (result * term) % MOD;
        } else {
            ll l = left_0[left_0.size() - 1];
            if (left_0.size() > 1) {
                result = (result * pow_2[l]) % MOD;
            } else {
                result = (result * pow_2[l - 1]) % MOD;
            }
        }

        cout << result << "\n";
    }
}