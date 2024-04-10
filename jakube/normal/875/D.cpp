#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    SegmentTree(){};

	SegmentTree(std::vector<int> const &values) {
		n = values.size();
		data = std::vector<pair<int, int>>(2 * n);
        for (int i = 0; i < n; i++) {
            data[i + n] = {values[i], i};
        }
		for (int idx = n - 1; idx > 0; idx--)
			data[idx] = std::max(data[idx * 2], data[idx * 2 + 1]);
	}

	pair<int, int> maximum(int left, int right) { // interval [left, right)
		pair<int, int> ret = { -1, -1 };
		left += n;
		right += n;

		while (left < right) {
			if (left & 1) ret = std::max(ret, data[left++]);
			if (right & 1) ret = std::max(ret, data[--right]);
			left >>= 1;
			right >>= 1;
		}
		return ret;
	}

private:
	int n;
	std::vector<pair<int, int>> data;
};

SegmentTree st;
vector<vector<int>> bits(32);

long long f(int l, int r) {
    if (l >= r)
        return 0;

    long long cnt = 0;

    auto m = st.maximum(l, r);
    int val = m.first;
    int idx = m.second;

    int L = l;
    int R = r;
    for (int j = 0; j < 31; j++) {
        if ((val & (1 << j)) == 0 && bits[j].size()) {
            auto lit = lower_bound(bits[j].begin(), bits[j].end(), idx);
            if (lit != bits[j].end()) {
                int lr = *lit;
                R = min(R, lr);
            }
            if (lit != bits[j].begin()) {
                --lit;
                int ll = *lit;
                L = max(L, ll + 1);
            }
        }
    }
    cnt += (long long)(idx + 1 - l) * (long long)(r - idx) - (long long)(idx + 1 - L) * (long long)(R - idx);

    cnt += f(l, idx);
    cnt += f(idx + 1, r);

    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 31; j++) {
            if (v[i] & (1 << j))
                bits[j].push_back(i);
        }
    }

    st = SegmentTree(v);
    cout << f(0, n) << endl;
}