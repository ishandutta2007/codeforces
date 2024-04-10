#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<ll> pref_c(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) pref_c[i + 1] = pref_c[i] + c[i];
        else pref_c[i + 1] = pref_c[i] - c[i];
    }

    vector<vector<ll>> left_count(n, vector<ll>(n, 0));
    vector<vector<ll>> right_count(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i += 2) {
        for (int j = i + 3; j < n; j += 2) {
            left_count[i][j] = max(left_count[i][j - 2], pref_c[i + 1] - pref_c[j - 1]);
        }
    }

    for (int j = n / 2 * 2 - 1; j >= 0; j -= 2) {
        for (int i = j - 3; i >= 0; i -= 2) {
            right_count[i][j] = max(right_count[i + 2][j], pref_c[j] - pref_c[i + 2]);
        }
    }
    
    ll totalCount = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = i + 1; j < n; j += 2) {
            if (j > i + 1) {
                ll extraBracket = pref_c[j] - pref_c[i + 1];
                ll leftCount = left_count[i][j];
                ll rightCount = right_count[i][j];

                ll left_c = c[i] - leftCount;
                ll right_c = c[j] - rightCount;
                extraBracket = extraBracket + leftCount - rightCount;
                ll adder = 0;
                if (left_c >= 0 && right_c >= 0) {
                    if (extraBracket > 0) {
                        if (right_c - extraBracket >= 0) {
                            adder = (ll) 1 + min(right_c - extraBracket, left_c);
                        }
                    } else {
                        extraBracket = -extraBracket;
                        if (left_c - extraBracket >= 0) {
                            adder = (ll) 1 + min(left_c - extraBracket, right_c);
                        }
                    }
                }
                totalCount += adder;
                // cout << "T " << i << " " << j << " " << leftCount << " " << rightCount << " " << extraBracket << " " << adder << "\n";
            } else {
                totalCount += min(c[i], c[j]);
            }
        }
    }

    cout << totalCount << "\n";

}