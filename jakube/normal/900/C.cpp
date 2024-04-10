#include <bits/stdc++.h>
using namespace std;

struct S
{
    vector<int> v;
};

S combine(S& a, S& b) {
    S res = a;
    for (int x : b.v) {
        if (x > res.v.back())
            res.v.push_back(x);
    }
    return res;
}
class SegmentTree {
public:
	SegmentTree(std::vector<int> const &values) {
		n = values.size();
		data = std::vector<S>(2 * n);
        for (int i = 0; i < n; i++) {
            data[i + n].v.push_back(values[i]);
        }
		for (int idx = n - 1; idx > 0; idx--)
			data[idx] = combine(data[idx * 2], data[idx * 2 + 1]);
	}

	pair<int, int> minimum(int left, int right, int val) { // interval [left, right)
		int ret = std::numeric_limits<int>::max();
		left += n;
		right += n;
        vector<int> x, y;

		while (left < right) {
			if (left & 1) x.push_back(left++);
			if (right & 1) y.push_back(--right);
			left >>= 1;
			right >>= 1;
		}

        reverse(y.begin(), y.end());
        x.insert(x.end(), y.begin(), y.end());

        int last = val;
        int cnt = 0;
        for (int idx : x) {
            auto v = data[idx].v;
            auto lit = upper_bound(v.begin(), v.end(), last);
            cnt += v.end() - lit;
            last = max(last, v.back());
        }

		return {cnt, last};
	}

private:
	int n;
	std::vector<S> data;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    SegmentTree st(v);
    int b = n;
    int c = -1;
    for (int i = 0; i < n; i++) {
        auto x = st.minimum(0, i, -1);
        auto y = st.minimum(i + 1, n, x.second);
        auto z = x.first + y.first;
        if (z > c) {
            c = z;
            b = v[i];
        } else if (z == c) {
            b = min(v[i], b);
        }
    }
    cout << b << endl;
}