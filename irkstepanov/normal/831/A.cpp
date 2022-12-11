
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int inf = 1e9;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int firstpos = 0, lastpos = 0;
	int maxx = a[0];

	for (int i = 0; i < n; ++i) {
		if (maxx < a[i]) {
			maxx = a[i];
			firstpos = i;
			lastpos = i;
		} else if (maxx == a[i]) {
			lastpos = i;
		}
	}

	for (int i = 0; i + 1 <= firstpos; ++i) {
		if (a[i] >= a[i + 1]) {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = firstpos; i + 1 <= lastpos; ++i) {
		if (a[i] != a[i + 1]) {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = lastpos; i + 1 < n; ++i) {
		if (a[i] <= a[i + 1]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

}