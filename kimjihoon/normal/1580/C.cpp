#include <iostream>
#include <algorithm>
using namespace std;

const int B = 500;
int d[509][509], x[200009], y[200009], op[200009], kp[200009], rp[200009], el[200009], sp[200009], rr[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> x[i] >> y[i];
	for (int i = 1; i <= m; i++) {
		cin >> op[i] >> kp[i];
		el[i] = m + 1;
		if (op[i] == 1) rp[kp[i]] = i;
		else el[rp[kp[i]]] = i;
	}
	int ss = 0;
	for (int i = 1; i <= m; i++) {
		int tx = x[kp[i]], ty = y[kp[i]], tt = tx + ty;
		if (tt <= B) {
			int t = 0, rt = 0;
			if (op[i] == 1) {
				t = 1;
				rt = (i + tx) % tt;
				rr[kp[i]] = rt;
			}
			else {
				t = -1;
				rt = rr[kp[i]];
			}
			for (int j = 0; j < ty; j++) {
				d[tt][rt] += t;
				rt++;
				if (rt >= tt) rt = 0;
			}
		}
		else if (op[i] == 1) {
			for (int j = i + tx; j < el[i]; j += tt) {
				sp[j]++;
				if (j + ty <= el[i])
					sp[j + ty]--;
				else
					sp[el[i]]--;
			}
		}
		ss += sp[i];
		int ans = ss;
		for (int j = 1; j <= B; j++)
			ans += d[j][i % j];
		cout << ans << '\n';
	}
	return 0;
}