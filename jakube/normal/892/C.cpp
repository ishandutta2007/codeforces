#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
	SegmentTree(std::vector<int> const &values) {
		n = values.size();
		data = std::vector<int>(2 * n);
		std::copy(values.begin(), values.end(), &data[0] + n);
		for (int idx = n - 1; idx > 0; idx--)
			data[idx] = __gcd(data[idx * 2], data[idx * 2 + 1]);
	}

	void update(int idx, int value) {
		idx += n;
		data[idx] = value;

		while (idx > 1) {
			idx /= 2;
			data[idx] = __gcd(data[2 * idx], data[2 * idx + 1]);
		}
	}

	int minimum(int left, int right) { // interval [left, right)
		int ret = 0;
		left += n;
		right += n;

		while (left < right) {
			if (left & 1) ret = __gcd(ret, data[left++]);
			if (right & 1) ret = __gcd(ret, data[--right]);
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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int g = accumulate(v.begin(), v.end(), 0, [](int a, int b){ return __gcd(a, b);});
    if (g > 1) {
        cout << -1 << endl;
    } else {
        int cnt = 0;
        for (int i : v)
            cnt += i == 1;
        if (cnt) {
            cout << n - cnt << endl;
            return 0;
        }

        SegmentTree st(v);
        // 0 .. L = false
        // R + ... true
        int L = 0, R = n;
        while (L  + 1 < R) {
            int M = (L + R) / 2;
            int ming = 2;
            for (int i = 0; i + M <= n; i++) {
                ming = min(ming, st.minimum(i, i + M));
            }
            if ( ming == 1)
                R = M;
            else 
                L = M;
        }
        cout << R - 2 + n << endl;
    }
}