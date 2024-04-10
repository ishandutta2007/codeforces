#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
	SegmentTree(int count) {
		n = count;
		data = std::vector<int>(2 * n, 0);
	}

	void increase(int idx) {
		idx += n;
		data[idx]++;

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

    int n = 1e7;
    vector<int> largest(n+1), smallest(n+1);
    iota(largest.begin(), largest.end(), 0);
    iota(smallest.begin(), smallest.end(), 0);
    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = i; j <= n; j += i) {
                largest[j] = i;
                smallest[j] = min(smallest[j], i);
            }
        }
    }

    long long result = 0;
    cin >> n;
    SegmentTree st(n+1);

    for (int i = 2; i <= n; i++) {
        int num = i;
        int co = 1;
        while (num > 1) {
            int s = largest[num];
            num /= s;
            int p1 = 1;
            int p2 = s;
            while (largest[num] == s) {
                num /= s;
                p1 = p2;
                p2 *= s;
            }
            co *= p2 - p1;
        }

        // cout << i << ": " << co << endl;
        int x = i - 1 - co;
        result += x;
        // cout << x << endl;
        // ^ these have distance 1
        
        // case gcd(a, b) == 1
        // smallest[a] * smallest[b] <= n
        // => distance 2
        // numbers = i - 1;
        int others = st.sum(0, n / smallest[i] + 1) - x;
        // cout << others << endl;
        result += others * 2;

        // last case
        if (smallest[i] != 2 && smallest[i] * 2 <= n) {
            int abc = st.sum(0, n / 2 + 1) - st.sum(0, n/smallest[i] + 1);
            result += abc* 3;


        }


        st.increase(smallest[i]);
    }

    cout << result << endl;
}