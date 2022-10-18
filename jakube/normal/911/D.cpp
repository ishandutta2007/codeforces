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
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    SegmentTree st(n + 1);
    int cnt = 0;
    for (int i : v) {
        cnt += st.sum(i, n+1);
        st.update(i, 1);
    }
    
    int inv = cnt % 2;
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int l = b - a + 1;
        inv = inv + l * (l - 1) / 2;
        inv %= 2;
        if (inv)
            cout << "odd" << '\n';
        else
            cout << "even" << '\n';
    }
}