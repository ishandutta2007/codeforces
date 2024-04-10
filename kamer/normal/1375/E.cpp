#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <unordered_set>
#include <tuple>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

struct IndexedTupleComparator {
    bool operator()(const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) {
        if (get<0>(lhs) == get<0>(rhs)) {
            return get<2>(lhs) > get<2>(rhs);
        }
        return get<0>(lhs) > get<0>(rhs);
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = i;
    vector<vector<int>> inv(n, vector<int>());
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) { 
                count++; 
                inv[j].push_back(i);
            }
        }
    }

    cout << count << "\n";
    for (int i = n - 1; i >= 0; i--) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, IndexedTupleComparator> invQueue;
        for (auto j : inv[i]) {
            invQueue.push(make_tuple(a[j], j, b[j]));
        }
        while (!invQueue.empty()) {
            auto indexedTuple = invQueue.top();
            invQueue.pop();
            swap(a[i], a[get<1>(indexedTuple)]);
            swap(b[i], b[get<1>(indexedTuple)]);
            cout << get<1>(indexedTuple) + 1 << " " << i + 1 << "\n";
        }
    }
}