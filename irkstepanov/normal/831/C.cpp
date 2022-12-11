
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n, k;
	cin >> n >> k;

	vector<int> sum(n);
	int curr = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		curr += a;
		sum[i] = curr;
	}

	vector<int> b(k);
	for (int i = 0; i < k; ++i) {
		cin >> b[i];
	}

	set<int> ans;
	for (int i = 0; i < n; ++i) {
		int x = b[0] - sum[i];
		set<int> setik;
		for (int j = 1; j < k; ++j) {
			setik.insert(b[j]);
		}
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			setik.erase(x + sum[j]);
		}
		if (setik.empty()) {
			ans.insert(x);
		}
	}

	cout << sz(ans) << "\n";
	
}