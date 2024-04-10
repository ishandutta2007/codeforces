#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[200009], lz[800009];

void lazy(int s, int e, int tn)
{
	if (lz[tn] != 0) {
		if (s == e && a[s] < lz[tn]) a[s] = lz[tn];
		if (s != e) {
			lz[tn * 2] = max(lz[tn * 2], lz[tn]);
			lz[tn * 2 + 1] = max(lz[tn * 2 + 1], lz[tn]);
		}
		lz[tn] = 0;
	}
}

void update(int tn, int s, int e, int tp, int w)
{
	lazy(s, e, tn);
	if (s == e && s == tp) {
		a[s] = w;
		return;
	}
	int md = (s + e) / 2;
	if (tp <= md) update(tn * 2, s, md, tp, w); 
	else update(tn * 2 + 1, md + 1, e, tp, w);
}

void lp(int tn, int s, int e)
{
	lazy(s, e, tn);
	if (s == e) return;
	int md = (s + e) / 2;
	lp(tn * 2, s, md);
	lp(tn * 2 + 1, md + 1, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 1) {
			int a, b; cin >> a >> b;
			update(1, 1, n, a, b);
		}
		else {
			int a; cin >> a;
			lz[1] = max(lz[1], a);
		}
	}
	lp(1, 1, n);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << '\n';
	return 0;
}