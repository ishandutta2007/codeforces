#include <bits/stdc++.h>
using namespace std;


class SegmentTree {
public:
	SegmentTree(std::vector<int> const &values) {
		n = values.size();
		data = std::vector<pair<int, int>>(2 * n);
        for (int i = 0; i < n; i++) {
            data.at(i + n) = {values.at(i), i + 1};
        }
		for (int idx = n - 1; idx > 0; idx--)
			data.at(idx) = std::max(data.at(idx * 2), data.at(idx * 2 + 1));
	}

	pair<int, int> maximum(int left, int right) { // interval [left, right)
		pair<int, int> ret = {0, 0};
		left += n;
		right += n;

		while (left < right) {
			if (left & 1) ret = std::max(ret, data.at(left++));
			if (right & 1) ret = std::max(ret, data.at(--right));
			left >>= 1;
			right >>= 1;
		}
		return ret;
	}

private:
	int n;
	std::vector<pair<int, int>> data;
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
    auto w = v;
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());

    vector<int> diff(n);
    for (int i = 0; i < n-1; i++) {
        diff[i] = w[i] - w[i+1];
    }
    diff.back() = w.back();

    SegmentTree st(diff);
    
    using S = array<int, 3>;

    S best = {{0, 0, 0}};
    for (int i = 1; i <= n; i++) {
        int mi = max(1, ((i + 1) / 2));
        int ma = i * 2;
        for (int j = mi; j <= ma; j++) {
            int MI = max(mi, (j + 1) / 2);
            int MA = min(ma, j*2);

            if (i + j + MI <= n) {
                int x = st.maximum(i + j + MI - 1, min(i + j + MA, n)).second;
                S xx = {{i, i + j, x}};
                if (best == S{{0, 0, 0}} || 
                        make_tuple(diff[best[0]-1], diff[best[1]-1], diff[best[2]-1])
                       < make_tuple(diff[xx[0]-1], diff[xx[1]-1], diff[xx[2]-1]))
                    best = xx;
            }
        }
    }

    vector<pair<int, int>> V;
    for (int i = 0; i < n; i++) {
        V.push_back({v[i], i});
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    
    for (int i = 0; i < n; i++) {
        if (i < best[0]) {
            V[i].first = 1;
        } else if (i < best[1]) {
            V[i].first = 2;
        } else if (i < best[2]) {
            V[i].first = 3;
        } else {
            V[i].first = -1;
        }
    }

    sort(V.begin(), V.end(), [](auto p, auto q) {
        return p.second < q.second;
    });

    for (auto p : V)
        cout << p.first << ' ';
    cout << endl;
}