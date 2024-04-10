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

	bool almost_gcd(int left, int right, int goal) { // interval [left, right)
		left += n;
		right += n;

        vector<pair<int, int>> v;
		while (left < right) {
			if (left & 1) v.push_back({data[left], left}), left++;
			if (right & 1) --right, v.push_back({data[right], right});
			left >>= 1;
			right >>= 1;
		}

        // all segments divisible by goal => possible
        // more than 2 not divisible => then not
        int cnt = 0;
        int which = -1;
        for (auto p : v) {
            if (p.first % goal) {
                cnt++;
                which = p.second;
            }
        }
        if (cnt == 0) {
            return true;
        }
        if (cnt > 1) {
            return false;
        }

        // check out this one segment more carefully
        while (which * 2 + 1 < (int)data.size()) {
            int ll = data[which << 1];
            int rr = data[which << 1 | 1];
            if (ll % goal == 0) {
                which = which << 1 | 1;
            } else if (rr % goal == 0) {
                which = which << 1;
            } else {
                return false;
            }
        }
		return true;
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
    SegmentTree st(v);

    int q;
    cin >> q;
    for (int Q = 0; Q < q; Q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            if (st.almost_gcd(l-1, r, x))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        } else {
            int i, y;
            cin >> i >> y;
            st.update(i-1, y);
        }
    }
}