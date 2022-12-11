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

	int n;
	cin >> n;

	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<ll> prefodd(n), prefeven(n);
	for (int i = 0; i < n; ++i) {
		if (i) {
			prefodd[i] = prefodd[i - 1];
			prefeven[i] = prefeven[i - 1];
		}
		if (i % 2 == 0) {
			prefodd[i] += a[i];
		} else {
			prefeven[i] += a[i];
		}
	}

	vector<ll> suffodd(n), suffeven(n);
	for (int i = n - 1; i >= 0; --i) {
		if (i != n - 1) {
			suffodd[i] = suffeven[i + 1];
			suffeven[i] = suffodd[i + 1];
		}
		suffodd[i] += a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ll odd = 0, even = 0;
		if (i) {
			odd += prefodd[i - 1];
			even += prefeven[i - 1];
		}
		if (i != n - 1) {
			if (i % 2 == 1) {
				even += suffodd[i + 1];
				odd += suffeven[i + 1];
			} else {
				even += suffeven[i + 1];
				odd += suffodd[i + 1];
			}
		}
		if (odd == even) {
			++ans;
		}
	}

	cout << ans << "\n";
	
}