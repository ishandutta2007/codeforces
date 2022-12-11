#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 100500;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = 1;
	vector<int> cnt(nmax);

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int d = 2; d * d <= a; ++d) {
			if (a % d == 0) {
				++cnt[d];
				while (a % d == 0) {
					a /= d;
				}
			}
		}
		if (a != 1) {
			++cnt[a];
		}
	}

	for (int i = 0; i < nmax; ++i) {
		ans = max(ans, cnt[i]);
	}
	cout << ans << "\n";

}