#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int nmax = 2550;

int sum[nmax][nmax];
int n, m;

bool isPrime(int p) {
	for (int d = 2; d * d <= p; ++d) {
		if (p % d == 0) {
			return false;
		}
	}
	return true;
}

int get(int i, int j, int p) {
	int ans = sum[min(i + p - 1, n - 1)][min(j + p - 1, m - 1)];
	if (i) {
		ans -= sum[i - 1][min(j + p - 1, m - 1)];
	}
	if (j) {
		ans -= sum[min(i + p - 1, n - 1)][j - 1];
	}
	if (i && j) {
		ans += sum[i - 1][j - 1];
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");
	
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			sum[i][j] = s[j] - '0';
			if (i) {
				sum[i][j] += sum[i - 1][j];
			}
			if (j) {
				sum[i][j] += sum[i][j - 1];
			}
			if (i && j) {
				sum[i][j] -= sum[i - 1][j - 1];
			}
		}
	}

	int ans = n * m;

	for (int p = 2; p <= max(n, m); ++p) {
		if (!isPrime(p)) {
			continue;
		}
		int sum = 0;
		for (int i = 0; i < n; i += p) {
			for (int j = 0; j < m; j += p) {
				int val = get(i, j, p);
				sum += min(val, p * p - val);
			}
		}
		ans = min(ans, sum);
	}

	cout << ans << "\n";

}