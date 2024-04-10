#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int inf = 1000000009;

string ss;
int st[400009][3][3];
char cr[3] = { 'a', 'b', 'c' };

void init(int tn, int s, int e)
{
	if (s == e) {
		for (int i = 0; i < 3; i++) {
			int t = 1;
			for (int j = i; j < 3; j++) {
				if (cr[j] != ss[s]) t = 0;
				st[tn][i][j] = t;
			}
		}
		return;
	}
	int md = (s + e) / 2;
	init(tn * 2, s, md);
	init(tn * 2 + 1, md + 1, e);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++) {
			st[tn][i][j] = inf;
			for (int k = i; k <= j; k++)
				st[tn][i][j] = min(st[tn][i][j], st[tn * 2][i][k] + st[tn * 2 + 1][k][j]);
		}
}

void update(int tn, int s, int e, int p)
{
	if (s == e) {
		for (int i = 0; i < 3; i++) {
			int t = 1;
			for (int j = i; j < 3; j++) {
				if (cr[j] != ss[s]) t = 0;
				st[tn][i][j] = t;
			}
		}
		return;
	}
	int md = (s + e) / 2;
	if (p <= md) update(tn * 2, s, md, p);
	else update(tn * 2 + 1, md + 1, e, p);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++) {
			st[tn][i][j] = inf;
			for (int k = i; k <= j; k++)
				st[tn][i][j] = min(st[tn][i][j], st[tn * 2][i][k] + st[tn * 2 + 1][k][j]);
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	cin >> ss;
	ss = " " + ss;
	init(1, 1, n);
	for (int i = 0; i < q; i++) {
		int p; char c; cin >> p >> c;
		ss[p] = c;
		update(1, 1, n, p);
		cout << st[1][0][2] << '\n';
	}
	return 0;
}