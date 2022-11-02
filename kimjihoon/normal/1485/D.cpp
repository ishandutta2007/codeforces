#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int pp[109];
int ar[509][509];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long ts = 1;
	for (long long i = 1; i <= 16; i++)
		ts = ts * i / gcd(ts, i);
	for (int i = 1; i <= 16; i++) {
		int tj = -1;
		for (int j = 1; j * i <= 1000000; j++) {
			int t = ts - j * i;
			if (t < 0) t *= -1;
			for (int k = 1; k <= 100; k++) {
				if (k * k * k * k == t) {
					tj = j;
					break;
				}
			}
			if (tj != -1) break;
		}
		pp[i] = i * tj;
	}
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> ar[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i + j) & 1) cout << ts << " ";
			else cout << pp[ar[i][j]] << " ";
		}
		cout << '\n';
	}
	return 0;
}