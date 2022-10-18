#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
	SegmentTree(int count) {
		n = count;
		data = std::vector<int>(2 * n, 0);
	}

	SegmentTree(std::vector<int> const &values) {
		n = values.size();
		data = std::vector<int>(2 * n);
		std::copy(values.begin(), values.end(), &data[0] + n);
		for (int idx = n - 1; idx > 0; idx--)
			data[idx] = std::min(data[idx * 2], data[idx * 2 + 1]);
	}

	void update(int idx, int value) {
		idx += n;
		data[idx] = value;

		while (idx > 1) {
			idx /= 2;
			data[idx] = std::min(data[2 * idx], data[2 * idx + 1]);
		}
	}

	int minimum(int left, int right) { // interval [left, right)
		int ret = std::numeric_limits<int>::max();
		left += n;
		right += n;

		while (left < right) {
			if (left & 1) ret = std::min(ret, data[left++]);
			if (right & 1) ret = std::min(ret, data[--right]);
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
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    SegmentTree st(v);
    
    if (k == 1) {
        cout << *min_element(v.begin(), v.end()) << endl;
    } else if (k == 2) {
        int res = numeric_limits<int>::min();
        for (int i = 0; i < n-1; i++) {
            res = max(res, max(st.minimum(0, i+1), st.minimum(i+1, n)));
        }
        cout << res << endl;
    } else {
        cout << *max_element(v.begin(), v.end()) << endl;
    }

}