#include <bits/stdc++.h>
using namespace std;

struct ByLength {
    int length, beauty, index;
    bool operator<(ByLength const& o) const {
        return tuple(length, beauty, index) < tuple(o.length, o.beauty, o.index);
    }
    ByLength(int length, int beauty, int index) : length(length), beauty(beauty), index(index){}
};

struct ByBeauty {
    int length, beauty, index;
    bool operator<(ByBeauty const& o) const {
        return tuple(beauty, length, index) < tuple(o.beauty, o.length, o.index);
    }
    ByBeauty(int length, int beauty, int index) : length(length), beauty(beauty), index(index){}
};

template<typename T1, typename T2>
T1 convert(T2 t) {
    return T1(t.length, t.beauty, t.index);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> tb(n);
    for (auto& x : tb)
        cin >> x.first >> x.second;

    set<ByBeauty> by_beauty;
    for (int i = 0; i < n; i++) {
        auto x = tb[i];
        by_beauty.insert({x.first, x.second, i});
    }

    set<ByLength> largest_k_minus_1;
    long long sum = 0;
    long long best = 0;
    while (!by_beauty.empty()) {
        auto x = *by_beauty.rbegin();
        by_beauty.erase(--by_beauty.end());

        best = max(best, (sum + x.length) * x.beauty);

        auto y = convert<ByLength>(x);
        if (largest_k_minus_1.size() < k - 1) {
            sum += y.length;
            largest_k_minus_1.insert(y);
        } else if (k-1 > 0 && largest_k_minus_1.begin()->length < y.length) {
            sum -= largest_k_minus_1.begin()->length;
            sum += y.length;
            largest_k_minus_1.erase(largest_k_minus_1.begin());
            largest_k_minus_1.insert(y);
        }
    }

    cout << best << '\n';
}