#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

const int MAXN = 524288;

int n;
int c[MAXN];
int flip[19];

int tree[2*MAXN];

void napravi() {
	for (int i=0; i<MAXN; i++) {
		tree[i + MAXN] = c[i] ? 0 : 1;
	}
	for (int i=MAXN-1; i>0; i--) {
		tree[i] = tree[2*i] + tree[2*i+1];
	}
}

int find_mex(int t, int l, int r, int bit) {

	if (bit == 0) {
		if (tree[t] == 1) {
			return l;
		} else {
			return -1;
		}
	}

	int lft = 2*t;
	int rgt = 2*t+1;

	if (flip[bit]) {
		swap(lft, rgt);
	}

	int m = (l+r) >> 1;

	if (tree[lft] > 0) {
		return find_mex(lft, l, m, bit-1);
	} else {
		return find_mex(rgt, m+1, r, bit-1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	napravi();
	// cerr << find_mex(1, 0, MAXN-1, 19) << '\n';

	while (q--) {
		int x;
		cin >> x;

		for (int i=0; i<19; i++) {
			if (x & (1<<i)) {
				flip[i+1] ^= 1;
			}
		}

		cout << find_mex(1, 0, MAXN-1, 19) << '\n';
	}
}