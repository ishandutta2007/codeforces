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

const ll BOUND = 100020;
vector<ll> digitSum(BOUND, 0);

ll findDigitSum(ll n) {
    ll res = 0;
    while (n > 0) {
        res = res + n % 10;
        n /= 10;
    }
    return res;
}

void preprocess() {
    for (ll i = 1; i < BOUND; i++) digitSum[i] = findDigitSum(i);
}

ll smallestInt(ll sum) {
    if (sum <= 9) return sum;
    ll countNine = sum / 9;
    ll remainder = sum % 9;
    for (ll i = 0; i < countNine; i++) {
        remainder = (remainder * 10) + 9;
    }
    return remainder;
}

ll smallestNoOverflowInt(ll sum) {
    if (sum <= 8) return sum;
    ll x = smallestInt(sum - 8);
    return x * 10 + 8;
}

ll smallestNoDOverflowInt(ll sum) {
    if (sum <= 7) return sum;
    ll x = smallestInt(sum - 7);
    return x * 10 + 7;
}

ll bruteforce(int n, int k) {
    ll initCount = 0;
    for (int i = 0; i <= k; i++) {
        initCount += digitSum[i];
    }
    if (initCount == n) return 0;
    for (int i = 1; i < BOUND - 13; i++) {
        initCount = initCount + digitSum[i + k] - digitSum[i - 1];
        if (initCount == n) return i;
    }
    return -1;
}

int main(void) {
    preprocess();
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if (k == 0) {
            cout << smallestInt(n) << "\n";
        } else if (k == 1) {
            if (n % 2 == 1) {
                cout << smallestNoOverflowInt((n - 1) / 2) << "\n";
            } else {
                if (n < 10) {
                    cout << "-1\n";
                } else {
                    cout << smallestNoOverflowInt((n - 10) / 2) * 10 + 9 << "\n";
                }
            }
        } else if (k == 2) {
            if (n % 3 != 0) {
                cout << "-1\n";
            } else {
                cout << smallestNoDOverflowInt(n / 3 - 1) << "\n";
            }
        } else {
            cout << bruteforce(n, k) << "\n";
        }
    }
}