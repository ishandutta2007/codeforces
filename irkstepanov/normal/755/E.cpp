#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (k > 3 || k > n - 1 || k == 1) {
		cout << "-1\n";
		return 0;
	}

	if (k == 3) {
		cout << 1 + 2 * (n - 3) + (n - 3) * (n - 4) / 2 << "\n";
		cout << "1 2\n";
		for (int x = 3; x < n; ++x) {
			cout << "2 " << x << "\n";
			cout << n << " " << x << "\n";
		}
		for (int x = 3; x < n; ++x) {
			for (int y = x + 1; y < n; ++y) {
				cout << x << " " << y << "\n";
			}
		}
		return 0;
	}

	if (k == 2) {
		if (n == 3 || n == 4) {
			cout << "-1\n";
			return 0;
		}
		cout << 2 * (n - 2) << "\n";
		for (int x = 2; x < n; ++x) {
			cout << "1 " << x << "\n";
		}
		for (int x = 3; x < n; ++x) {
			cout << n << " " << x << "\n";
		}
		cout << "2 3\n";
		return 0;
	}

}