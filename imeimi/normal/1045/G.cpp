#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, k;

struct robot {
    int x, r, q;
    void scan() {
        cin >> x >> r >> q;
    }
    bool operator<(const robot &p) const {
        return r < p.r;
    }
} rs[100000];

vector<int> cp;
struct fen {
    vector<int> cp;
    vector<int> seg;
    void pushElement(int x) {
        cp.push_back(x);
    }
    void init() {
        sort(cp.begin(), cp.end());
        cp.erase(unique(cp.begin(), cp.end()), cp.end());
        seg.resize(cp.size(), 0);
    }
    void update(int i) {
        i = lower_bound(cp.begin(), cp.end(), i) - cp.begin() + 1;
        while (i <= seg.size()) {
            ++seg[i - 1];
            i += i & -i;
        }
    }
    int query(int i) {
        i = upper_bound(cp.begin(), cp.end(), i) - cp.begin();
        int ret = 0;
        while (i) {
            ret += seg[i - 1];
            i -= i & -i;
        }
        return ret;
    }
};

map<int, fen> seg;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
        rs[i].scan();
        seg[rs[i].q].pushElement(rs[i].x);
	}
	for (auto &i : seg) i.second.init();
	llong ans = 0;
	sort(rs, rs + n);
	for (int i = n; i--; ) {
        auto it = seg.lower_bound(rs[i].q - k);
        while (it != seg.end() && it->first <= rs[i].q + k) {
            ans += it->second.query(rs[i].x + rs[i].r) - it->second.query(rs[i].x - rs[i].r - 1);
            ++it;
        }
        seg[rs[i].q].update(rs[i].x);
	}
	printf("%lld\n", ans);
	return 0;
}