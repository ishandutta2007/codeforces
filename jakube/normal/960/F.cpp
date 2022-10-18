#include <bits/stdc++.h>
using namespace std;

template <typename T, typename S>
class MonotoneStorage {
public:
    void insert(T x, S y) {
        auto it = storage.upper_bound(x);
        if (it != storage.begin()) {
            auto prev = it;
            --prev;
            if (prev->second >= y)
                return;
            if (it->first == x)
                it = prev;
        }

        auto ti = it;
        while (ti != storage.end() && y >= ti->second)
            ++ti;
        
        storage.erase(it, ti);
        storage[x] = y;
    }

    S max_upto(T x) {
        auto it = storage.upper_bound(x);
        if (it == storage.begin())
            return 0;
        --it;
        return it->second;
    }

private:
    std::map<T, S> storage;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<MonotoneStorage<int, int>> sts(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        int longest = sts[a].max_upto(w);
        sts[b].insert(w, longest + 1);
    }

    int best = 0;
    for (int i = 0; i <= n; i++)
        best = max(best, sts[i].max_upto(100'001));
    cout << best << endl;
}