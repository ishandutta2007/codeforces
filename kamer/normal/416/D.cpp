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
using namespace std;
typedef long long ll;
ll MIN_NUM = -10000000000;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    if (n == 1) {
        cout << "1\n";
        return 0;
    } else if (n == 2) {
        cout << "1\n";
        return 0;
    }

    vector<tuple<ll, ll>> a;
    ll currOnes = 0;
    for (ll i = 0; i < n; i++) {
        if (nums[i] == -1) currOnes++;
        else {
            a.emplace_back(nums[i], currOnes);
            currOnes = 0;
        }
    }
    ll lastOnes = currOnes;

    ll k = a.size();
    if (k == 0) {
        cout << "1\n";
        return 0;
    }

    ll currProg = MIN_NUM;
    ll numProg = 0;
    ll unhandledPrev = get<1>(a[0]);

    for (ll i = 1; i < k; i++) {
        if (currProg == MIN_NUM) {
            if ((get<0>(a[i]) - get<0>(a[i - 1])) % (get<1>(a[i]) + 1) == 0) {
                ll tentativeProg = (get<0>(a[i]) - get<0>(a[i - 1])) / (get<1>(a[i]) + 1);
                if (get<0>(a[i]) - tentativeProg * (get<1>(a[i]) + 1 + unhandledPrev) <= 0) {
                    numProg++;
                    unhandledPrev = 0;
                    currProg = MIN_NUM;
                } else {
                    currProg = tentativeProg;
                    unhandledPrev = 0;
                }
            } else {
                numProg++;
                unhandledPrev = 0;
                currProg = MIN_NUM;
            }
        } else {
            if (get<0>(a[i]) - get<0>(a[i - 1]) == currProg * (get<1>(a[i]) + 1)) {
                unhandledPrev = 0;
            } else {
                numProg++;
                if (currProg >= 0) {
                    unhandledPrev = 0;
                } else {
                    unhandledPrev = get<1>(a[i]) - min(get<1>(a[i]), (get<0>(a[i - 1]) - 1) / (-currProg));
                }
                currProg = MIN_NUM;
            }
        }
    }
    numProg++;
    if (lastOnes > 0) {
        if (currProg == MIN_NUM) {
            // do nothing
        } else {
            if (get<0>(a[k - 1]) - currProg * unhandledPrev <= 0 || get<0>(a[k - 1]) + currProg * lastOnes <= 0) {
                numProg++;
            }
        }
    }
    cout << numProg << "\n";
}