#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, s;
	cin >> n >> s;
	--s;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	if (!a[0]) {
		cout << "NO\n";
		return 0;
	}

	bool ok = false;
	if (a[s]) {
		ok = true;
	}
	for (int i = s + 1; i < n; ++i) {
		if (a[i] && b[i] && b[s]) {
			ok = true;
		}
	}

	cout << (ok ? "YES\n" : "NO\n");
	
}