#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
//#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cin >> t;
    while (t--)
        solve();
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int n;
int b[100500];
int INF = 1000000000;
const int shift = 1 << 17;
int tree1[2 * shift + 6];
int rmq1 (int l, int r) {
	if (l > r)
		return INF;
	/*if (l == shift && r == shift) {
		cout << "see: " << tree1[r] << ' ' << rmq1(l, r - 1) << endl;
	}*/
	if (l % 2)
		return min(tree1[l], rmq1(l + 1, r));
	if (!(r % 2))
		return min(tree1[r], rmq1(l, r - 1));
	return rmq1(l / 2, r / 2);
}

void modify1 (int l, int val) {
	tree1[l] = val;
	l /= 2;
	while (l > 0) {
		tree1[l] = min(tree1[2 * l], tree1[2 * l + 1]);
		l /= 2;
	}
}

vector<int> poses[100500];

int l[100500], r[100500];
vector<int> nums[100500];

int last[100500];

int tree2[2 * shift + 6];

void modify (int l, int val) {
	tree2[l] = val;
	l /= 2;
	while (l > 0) {
		tree2[l] = tree2[2 * l] + tree2[2 * l + 1];
		l /= 2;
	}
}

int sum2 (int l, int r) {
	if (l > r)
		return 0;
	if (l % 2)
		return tree2[l] + sum2(l + 1, r);
	if (!(r % 2))
		return tree2[r] + sum2(l, r - 1);
	return sum2(l / 2, r / 2);
}

int res[100500];

int bad[100500];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		poses[b[i]].push_back(i);
	}
	for (int num = 0; num <= 100000; ++num) {
		for (int i = 0; i < poses[num].size(); ++i) {
			int cur = poses[num][i];
			if (i <= 1) {
				bad[cur] = -1;
				continue;
			}
			if (poses[num][i - 2] + poses[num][i] != 2 * poses[num][i - 1])
				bad[cur] = poses[num][i - 2];
			else
				bad[cur] = bad[poses[num][i - 1]];
		}
	}

	for (int i = 0; i < n; ++i)
		tree1[i + shift] = n + 1;
	for (int i = shift - 1; i > 0; --i)
		tree1[i] = min(tree1[2 * i], tree1[2 * i + 1]);

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> l[i] >> r[i];
		--l[i]; --r[i];
		nums[r[i]].push_back(i);
	}

	memset(last, -1, sizeof last);
	for (int i = 0; i < n; ++i) {
		if (last[b[i]] != -1) {
			modify(last[b[i]] + shift, 0);
			modify1(last[b[i]] + shift, n + 1);
		}
		last[b[i]] = i;
		modify(i + shift, 1);
		modify1(i + shift, bad[i]);
		for (int j = 0; j < nums[i].size(); ++j) {
			res[nums[i][j]] += sum2(l[nums[i][j]] + shift, i + shift);
			int now = rmq1(l[nums[i][j]] + shift, i + shift);
			//cout << l[nums[i][j]] << ' ' << i << ' ' << now << endl;
			if (now >= l[nums[i][j]])
				++res[nums[i][j]];
		}
	}

	for (int i = 0; i < Q; ++i)
		cout << res[i] << '\n';

}