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

int solve(vector<int>& a, vector<int>& indices, int bit) {
    if (indices.size() <= 3) {
        return indices.size();
    }
    
    vector<vector<int>> bit_ind(bit + 1, vector<int>());
    vector<int> count(bit + 2, 0);
    vector<int> sol(bit + 2, 0);
    for (auto ind : indices) {
        auto el = a[ind];
        bool broke = false;
        for (int j = bit; j >= 0; j--) {
            if (el & (1 << j)) {
                count[j + 1]++;
                bit_ind[j].push_back(ind);
                broke = true;
                break;
            }
        }
        if (!broke) {
            count[0] = 1;
            sol[0] = 1;
        }
    }

    for (int new_bit = bit; new_bit >= 0; new_bit--) {
        sol[new_bit + 1] = solve(a, bit_ind[new_bit], new_bit - 1);
    }

    vector<int> pref(bit + 2, 0);
    vector<int> suf(bit + 2, 0);
    for (int i = 1; i <= bit + 1; i++) {
        pref[i] = pref[i - 1];
        if (count[i - 1]) pref[i] = 1;
    }

    for (int i = bit; i >= 0; i--) {
        suf[i] = suf[i + 1];
        if (count[i + 1]) suf[i]++;
    }

    int res = 0;
    for (int i = 0; i <= bit + 1; i++) {
        res = max(res, suf[i] + sol[i] + pref[i]);
    }

    return res;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ind(n);
    for (int i = 0; i < n; i++) ind[i] = i;
    cout << n - solve(a, ind, 29) << "\n";
}