#include <iostream>
#include <algorithm>
using namespace std;

int a[100009], lz[800099], ans[200009], g = 100001;

void init(int tn, int ts, int te)
{
	if (ts == te) {
		lz[tn] = 1;
		return;
	}
	int md = (ts + te) / 2;
	init(tn * 2, ts, md); init(tn * 2 + 1, md + 1, te);
}

void up_lazy(int tn, int ts, int te)
{
	if (lz[tn] != 0 && ts != te) {
		if (lz[tn] == -1) {
			if (lz[tn * 2] == -1) lz[tn * 2] = 0;
			else if (lz[tn * 2] == 0) lz[tn * 2] = -1;
			else lz[tn * 2] = (lz[tn * 2] % 2) + 1;
			if (lz[tn * 2 + 1] == -1) lz[tn * 2 + 1] = 0;
			else if (lz[tn * 2 + 1] == 0) lz[tn * 2 + 1] = -1;
			else lz[tn * 2 + 1] = (lz[tn * 2 + 1] % 2) + 1;
		}
		else {
			lz[tn * 2] = lz[tn];
			lz[tn * 2 + 1] = lz[tn];
		}
		lz[tn] = 0;
	}
}

void up(int tn, int ts, int te, int s, int e, int w)
{
	up_lazy(tn, ts, te);
	if (te < s || e < ts) return;
	if (s <= ts && te <= e) {
		if (w == -1) {
			if (lz[tn] == 0) lz[tn] = -1;
			else if (lz[tn] == -1) lz[tn] = 0;
			else lz[tn] = (lz[tn] % 2) + 1;
		}
		else
			lz[tn] = w;
		up_lazy(tn, ts, te);
		return;
	}
	int md = (ts + te) / 2;
	up(tn * 2, ts, md, s, e, w); up(tn * 2 + 1, md + 1, te, s, e, w);
}

void pa(int tn, int ts, int te)
{
	up_lazy(tn, ts, te);
	if (ts == te) {
		if (lz[tn] == 1) ans[ts] = 1;
		else ans[ts] = -1;
		return;
	}
	int md = (ts + te) / 2;
	pa(tn * 2, ts, md); pa(tn * 2 + 1, md + 1, te);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	init(1, 1, 200001);
	for (int i = 0; i < q; i++) {
		char c; int x; cin >> c >> x;
		int s = 1, e = 200001;
		if (c == '>') s = min(x + g + 1, 200001);
		else e = max(1, x + g - 1);
		int t = max(min(e - g, g - s), 0);
		if (t > 0) {
			up(1, 1, 200001, g - t, g + t, -1);
			if (s == 1) e -= 2 * t + 1;
			else s += 2 * t + 1;
		}
		if (s <= e) {
			up(1, 1, 200001, s, e, 2);
			up(1, 1, 200001, 2 * g - e, 2 * g - s, 1);
		}
	}
	pa(1, 1, 200001);
	for (int i = 0; i < n; i++) 
		cout << a[i] * ans[(a[i] + g)] << " ";
	cout << '\n';
	return 0;
}