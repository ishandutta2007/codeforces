#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    int n, b;
    cin >> n >> b;
    typedef pair<int, int> pii;
    vector<pii> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    vector<long long> f = {0};
    for (auto q: queries) {
        auto it = upper_bound(f.begin(), f.end(), q.first);
        long long r = -1;
        if (f.end() - it <= b) {
            r = max((long long)q.first, f.back()) + q.second;
            f.push_back(r);
        }
        cout << r << " ";
    }
    cout << endl;
}