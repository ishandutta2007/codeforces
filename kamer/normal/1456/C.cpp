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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll pos_contribution = 0;
    ll pos_sum = 0;
    int last_index = -1;
    for (int i = 0; i < n; i++) {
        pos_contribution += pos_sum;
        pos_sum += a[i];
        if (pos_sum < 0) {
            last_index = i + 1;
            break;
        }
    }

    if (last_index == n || pos_sum >= 0) {
        cout << pos_contribution << "\n";
        return 0;
    }

    vector<ll> c(n - last_index + 1);
    c[0] = pos_sum;
    for (int i = last_index; i < n; i++) {
        c[i - last_index + 1] = a[i];
    }

    n = n - last_index + 1;
    k++;

    vector<vector<ll>> batches(k, vector<ll>());
    for (int i = n - 1; i >= 0; i--) {
        batches[i % k].push_back(c[i]);
    }
    ll neg_contribution = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < batches[i].size(); j++) {
            neg_contribution += batches[i][j] * j;
        }
    }

    cout << pos_contribution + neg_contribution << "\n";
}