#include <bits/stdc++.h>
using namespace std;

vector<long long> tens;
long long prime;


struct Segment {
    int size = 1;
    long long value = 0;
};

Segment combine(Segment a, Segment b) {
    Segment res;
    res.size = a.size + b.size;
    res.value = (a.value * tens[b.size] + b.value) % prime;
    return res;
}

class SegmentTree {
public:
	SegmentTree(int count) {
		n = count;
		data.resize(2 * n);
	}

	SegmentTree(std::vector<Segment> const &values) {
		n = values.size();
		data.resize(2 * n);
        for (int idx = 0; idx < n; idx++)
            data[idx + n] = values[idx];
		for (int idx = n - 1; idx > 0; idx--)
			data[idx] = combine(data[idx * 2], data[idx * 2 + 1]);
	}

	void update(int idx, Segment value) {
		idx += n;
		data[idx] = value;

		while (idx > 1) {
			idx /= 2;
			data[idx] = combine(data[2 * idx], data[2 * idx + 1]);
		}
	}

	Segment query(int left, int right) { // interval [left, right)
		Segment ret_l, ret_r;
		left += n;
		right += n;

		while (left < right) {
			if (left & 1) ret_l = combine(ret_l, data[left++]);
			if (right & 1) ret_r = combine(data[--right], ret_r);
			left >>= 1;
			right >>= 1;
		}
		return combine(ret_l, ret_r);
	}

private:
	int n;
	std::vector<Segment> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prime = 982'451'653; // 50'000'000th prime
    tens.push_back(1);
    for (int i = 0; i < 1'000'005; i++) {
        tens.push_back(tens.back() * 10 % prime);
    }

    string s;
    cin >> s;
    int n = s.size();
    vector<Segment> segs(s.size());
    for (int i = 0; i < n; i++) {
        segs[i] = {1, s[i] - '0'};
    }
    SegmentTree st(segs);

    for (int a = 1; a < n; a++) {
        // case 1: a < b
        // a + 2*b = n or a + 2*b + 1 = n
        int b = (n - a) / 2;
        if (a <= b) {
            auto A = st.query(0, a).value;
            auto B = st.query(a, a + b).value;
            auto C = st.query(a + b, n).value;
            if ((b == 1 || s[a] != '0') && (n - a - b == 1 || s[a + b] != '0') && (A + B) % prime == C) {
                cout << s.substr(0, a) << "+" << s.substr(a, b) << "=" << s.substr(a + b) << endl;
                return 0;
            }
        }

        // case 2: a > b
        // 2 * a + b = n or 2 * a + b + 1 = n
        b = n - 2 * a;
        if (a > b && b > 0) {
            auto A = st.query(0, a).value;
            auto B = st.query(a, a + b).value;
            auto C = st.query(a + b, n).value;
            if ((b == 1 || s[a] != '0') && (n - a - b == 1 || s[a + b] != '0') && (A + B) % prime == C) {
                cout << s.substr(0, a) << "+" << s.substr(a, b) << "=" << s.substr(a + b) << endl;
                return 0;
            }
        }

        b = n - 2 * a - 1;
        if (a > b && b > 0) {
            auto A = st.query(0, a).value;
            auto B = st.query(a, a + b).value;
            auto C = st.query(a + b, n).value;
            if ((b == 1 || s[a] != '0') && (n - a - b == 1 || s[a + b] != '0') && (A + B) % prime == C) {
                cout << s.substr(0, a) << "+" << s.substr(a, b) << "=" << s.substr(a + b) << endl;
                return 0;
            }
        }
    }
}