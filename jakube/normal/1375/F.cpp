#include "bits/stdc++.h"
using namespace std;

template<typename T>
T max(const vector<T>& v) {
    return *max_element(v.begin(), v.end());
}

template<typename T>
T sum(const vector<T>& v) {
    return accumulate(v.begin(), v.end(), T());
}

/**
 * Compute an array that tells the positions of the smallest,
 * the second smallest, ... up to the largest number in the given array.
 */
template<typename T>
vector<int> get_ordering(const vector<T>& v) {
    int n = v.size();
    vector<pair<T, int>> with_indices(n);
    for (int i = 0; i < n; i++) {
        with_indices[i] = {v[i], i};
    }
    sort(with_indices.begin(), with_indices.end());

    vector<int> inverse(n);
    for (int i = 0; i < n; i++) {
        inverse[i] = with_indices[i].second;
    }
    return inverse;
}

int query(long long x) {
    cout << x << endl;
    int ans;
    cin >> ans;
    return ans - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> v(3);
    for (auto& x : v)
        cin >> x;

    cout << "First" << endl;
    int last_move = -1;
    while (true) {
        if (last_move != -1) {
            auto ord = get_ordering(v);
            auto diff1 = v[ord[2]] - v[ord[1]];
            auto diff2 = v[ord[1]] - v[ord[0]];
            if (last_move == ord[2] && diff1 == diff2) {
                int x = query(diff1);
                assert(x == -1);
                return 0;
            }
        }
        auto x = 3 * max(v) - sum(v);
        last_move = query(x);
        v[last_move] += x;
    }
}