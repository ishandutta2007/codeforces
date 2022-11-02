#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int B = 500;
int m, a[200009], c[509];
long long ft[2][300009], ans[200009], sc[509];

void up(int i, int w, int t)
{
	while (i <= m) {
		ft[t][i] += w;
		i += (i & (-i));
	}
}

long long qry(int i, int t)
{
	long long s = 0;
	while (i) {
		s += ft[t][i];
		i -= (i & (-i));
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	long long s = 0, pc = 0;
	for (int i = 1; i <= n; i++) {
		ans[i] = ans[i - 1] + s + 1LL * a[i] * (i - 1);
		if (a[i] <= B) 
			ans[i] -= sc[a[i]];
		for (int j = 1; j <= min(B, a[i]); j++) {
			ans[i] -= 1LL * c[j] * (a[i] / j * j);
			sc[j] += a[i] / j * j;
		}
		if (a[i] <= B)
			c[a[i]]++;	
		else {
			ans[i] -= qry(a[i], 1);
			for (int j = a[i]; j <= m; j += a[i]) {
				ans[i] -= (pc - qry(j - 1, 0)) * a[i];
				up(j, a[i], 1);
			}
			up(a[i], 1, 0);
			pc++;
		}
		cout << ans[i] << " ";
		s += a[i];
	}
	cout << '\n';
	return 0;
}