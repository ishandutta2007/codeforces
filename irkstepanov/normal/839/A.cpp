#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int curr = 0;
	for (int i = 0; i < n; ++i) {
		curr += a[i];
		int give = min(8, curr);
		k -= give;
		curr -= give;
		if (k <= 0) {
			cout << i + 1 << "\n";
			return 0;
		}
	}

	cout << "-1\n";

}