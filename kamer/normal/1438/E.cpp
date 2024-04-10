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
using namespace std;
typedef long long ll;

inline void inc_count(vector<ll>& a, vector<ll>& prefix_sums, int index1, int index2, int& count) {
    if (index2 <= index1 + 1) return;
    if ((a[index1] ^ a[index2]) == (prefix_sums[index2] - prefix_sums[index1 + 1])) {
        count++;
    }
}

// l inclusive, r exclusive, index gives mask
int get_count(vector<ll>& a, vector<ll>& prefix_sums, int l, int r, int index) {
    if (index == 0) return 0;
    if (r <= l + 2) return 0;

    int count = 0;
    ll mask = (ll) 1 << index;
    vector<ll> high_a;
    high_a.push_back(l - 1);
    for (int i = l; i < r; i++) {
        if (a[i] & mask) high_a.push_back(i);
    }
    high_a.push_back(r);

    int high_a_size = high_a.size();
    
    // first get both endpoints in high_a
    for (int i = 1; i < high_a_size - 2; i++) {
        inc_count(a, prefix_sums, high_a[i], high_a[i + 1], count);
    }

    // second get left endpoint in high_a only and no jump
    for (int i = 1; i < high_a_size - 1; i++) {
        for (int j = high_a[i] + 2; j < high_a[i + 1]; j++) {
            inc_count(a, prefix_sums, high_a[i], j, count);
        }
    }

    // third get right endpoint in high_a only no jumps
    for (int i = 1; i < high_a_size - 1; i++) {
        for (int j = high_a[i - 1] + 1; j < high_a[i] - 1; j++) {
            inc_count(a, prefix_sums, j, high_a[i], count);
        }
    }

    // fourth get left endpoint in high_a one jump
    for (int i = 1; i < high_a_size - 2; i++) {
        for (int j = high_a[i + 1] + 1; j < high_a[i + 2]; j++) {
            inc_count(a, prefix_sums, high_a[i], j, count);
        }
    }

    // fifth get right endpoint in high_a one jump
    for (int i = 2; i < high_a_size - 1; i++) {
        for (int j = high_a[i - 2] + 1; j < high_a[i - 1]; j++) {
            inc_count(a, prefix_sums, j, high_a[i], count);
        }
    }

    // sixth and final do recursive calls
    for (int i = 0; i < high_a_size - 1; i++) {
        count += get_count(a, prefix_sums, high_a[i] + 1, high_a[i + 1], index - 1);
    }

    return count;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> prefix_sums(n + 1);
    prefix_sums[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix_sums[i + 1] = prefix_sums[i] + a[i];
    }
    cout << get_count(a, prefix_sums, 0, n, 29) << "\n";
}