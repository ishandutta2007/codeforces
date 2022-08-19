#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Heap {
private:
    priority_queue<T> h, e;
    void maintain() {
        while (!e.empty() && h.top() == e.top()) {
            h.pop();
            e.pop();
        }
    }
public:
    void erase(const T &value) {
        e.push(value);
    }
    void push(const T &value) {
        h.push(value);
    }
    void pop() {
        maintain();
        h.pop();
    }
    const T &top() {
        maintain();
        return h.top();
    }
    bool empty() {
        return h.size() == e.size();
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t, q;
    cin >> n >> t >> q;
    vector<int> p(n), l(n), my(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    Heap<pair<double, int>> hAdd, hRemove;
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        hAdd.push({1.0 * p[i] / (l[i] + 1), i});
    }
    double ans = 0;
    cout << setprecision(10) << fixed;
    auto clear = [&](int r) {
        ans -= 1.0 * my[r] / (my[r] + l[r]) * p[r];
        if (my[r] < l[r])
            hAdd.erase({1.0 * p[r] * l[r] / (my[r] + l[r]) / (my[r] + l[r] + 1), r});
        if (my[r] > 0)
            hRemove.erase({-1.0 * p[r] * l[r] / (my[r] + l[r] - 1) / (my[r] + l[r]), r});
    };
    auto maintain = [&](int r) {
        ans += 1.0 * my[r] / (my[r] + l[r]) * p[r];
        if (my[r] < l[r])
            hAdd.push({1.0 * p[r] * l[r] / (my[r] + l[r]) / (my[r] + l[r] + 1), r});
        if (my[r] > 0)
            hRemove.push({-1.0 * p[r] * l[r] / (my[r] + l[r] - 1) / (my[r] + l[r]), r});
    };
    auto add = [&](int r) {
        clear(r);
        ++my[r];
        maintain(r);
    };
    auto remove = [&](int r) {
        if (r == -1) {
            --t;
            return;
        }
        clear(r);
        --my[r];
        maintain(r);
    };
    for (int i = 0; i < q; ++i) {
        int type, r;
        cin >> type >> r;
        --r;
        clear(r);
        if (type == 1) {
            ++l[r];
        } else {
            --l[r];
            if (my[r] > l[r]) {
                --my[r];
                ++t;
            }
        }
        maintain(r);
        while (!hAdd.empty() && hAdd.top().first + (t > 0 ? 0.0 : hRemove.top().first) > 0) {
            int idAdd = hAdd.top().second;
            int idRemove = t > 0 ? -1 : hRemove.top().second;
            assert(idAdd != idRemove);
            add(idAdd);
            remove(idRemove);
        }
        cout << ans << "\n";
    }
    return 0;
}