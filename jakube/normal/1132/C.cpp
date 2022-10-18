#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data.assign(2 * n, 0);
    }

    SegmentTree(std::vector<int> const &values) {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = data[2 * idx] + data[2 * idx + 1];
    }

    void update(int idx, int value) {
        idx += n;
        data[idx] = value;

        while (idx > 1) {
            idx /= 2;
            data[idx] = data[2 * idx] + data[2 * idx + 1];
        }
    }

    int sum(int left, int right) { // interval [left, right)
        int ret = 0;
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) ret += data[left++];
            if (right & 1) ret += data[--right];
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<int> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<pair<int, int>> v(q);
    for (auto& x : v) {
        cin >> x.first >> x.second;
        x.first--;
        x.second--;
    }
    
    vector<int> cnt(n, 0);
    for (auto [l, r] : v) {
        for (int i = l; i <= r; i++) {
            cnt[i]++;
        }
    }

    vector<int> one_vec = cnt, two_vec = cnt;
    for (auto& x : one_vec) {
        x = (int)(x == 1);
    }
    for (auto& x : two_vec) {
        x = (int)(x == 2);
    }

    int total = std::count_if(cnt.begin(), cnt.end(), [](int x){ return x > 0; });

    SegmentTree ones(one_vec);
    SegmentTree twos(two_vec);
    int best = std::numeric_limits<int>::max();

    sort(v.begin(), v.end());
    for (int i = 0; i < q; i++) {
        for (int j = i + 1; j < q; j++) {
            
            int c = 0;
            if (v[i].second < v[j].first) {
                c += ones.sum(v[i].first, v[i].second+1);
                c += ones.sum(v[j].first, v[j].second+1);
            } else if (v[i].second >= v[j].second) {
                c += ones.sum(v[i].first, v[j].first);
                c += twos.sum(v[j].first, v[j].second+1);
                c += ones.sum(v[j].second+1, v[i].second + 1);
            } else {
                c += ones.sum(v[i].first, v[j].first);
                c += twos.sum(v[j].first, v[i].second+1);
                c += ones.sum(v[i].second+1, v[j].second + 1);
            }
            best = min(best, c);
        }
    }

    cout << total - best << '\n';
}