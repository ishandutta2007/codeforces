#include <vector>
#include <iostream>
using namespace std;

int n;

typedef pair<int, int> pii;

vector<pii> gauss(vector<int> &v) {
	vector<pii> log;
	for (int i = 30, pos = 0; i >= 0; --i) {
		int idx = -1;
		for (int j = pos; j < n; ++j) {
			if (v[j] & (1 << i)) {
				idx = j;
				break;
			}
		}
		if (idx == -1)
			continue;
		if (idx != pos) {
			v[pos] ^= v[idx];
			log.push_back(pii(pos, idx));
		}
		for (int j = 0; j < n; ++j) {
			if (j == pos) continue;
			if (v[j] & (1 << i)) {
				v[j] ^= v[pos];
				log.push_back(pii(j, pos));
			}
		}
		++pos;
	}
	return log;
}

int highest_bit(int p) {
	p |= (p >> 1);
	p |= (p >> 2);
	p |= (p >> 4);
	p |= (p >> 8);
	p |= (p >> 16);
	return (p + 1) >> 1;
}

int main(void) {
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i <n; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i <n; ++i) {
		cin >> y[i];
	}
	vector<int> orig_x = x, orig_y = y;
	vector<pii> x_log = gauss(x);
	vector<pii> y_log = gauss(y);
	vector<pii> merge_log;
	for (int i = 0, j = 0; i < n; ++i) {
		if (y[i] == 0) {
			for (; j < n; ++j) {
				if (x[j] != 0) {
					merge_log.push_back(pii(j, j));
					x[j] ^= x[j];
				}
			}
			break;
		}
		while (j < n && highest_bit(x[j]) > highest_bit(y[i])) {
			merge_log.push_back(pii(j, j));
			x[j] ^= x[j];
			++j;
		}
		if (j == n || highest_bit(x[j]) < highest_bit(y[i])) {
			cout << -1 << endl;
			return 0;
		}
		for (int k = j + 1; k < n && x[j] != y[i]; ++k) {
			int b1 = highest_bit(x[k]);
			int b2 = highest_bit(x[j] ^ y[i]);
			if (b2 > b1) {
				break;
			}
			if (b1 == b2) {
				x[j] ^= x[k];
				merge_log.push_back(pii(j, k));
			}
		}
		if (x[j] != y[i]) {
			cout << -1 << endl;
			return 0;
		}
		if (j != i) {
			merge_log.push_back(pii(j, i));
			x[j] ^= x[i];
			merge_log.push_back(pii(i, j));
			x[i] ^= x[j];
			merge_log.push_back(pii(j, j));
			x[j] ^= x[j];
		}
		++j;
	}
	vector<pii> result;
	result.insert(result.end(), x_log.begin(), x_log.end());
	result.insert(result.end(), merge_log.begin(), merge_log.end());
	result.insert(result.end(), y_log.rbegin(), y_log.rend());
	x = orig_x;
	y = orig_y;
	cout << result.size() << endl;
	for (int i = 0; i < (int)result.size(); ++i) {
		x[result[i].first] ^= x[result[i].second];
		cout << result[i].first + 1 << " " << result[i].second + 1 << endl;
	}
	if (x != y) {
		return 1;
	}
	return 0;
}