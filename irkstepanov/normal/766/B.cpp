#include <bits/stdc++.h>

#define sz(a) (int)(a).size()
#define pb push_back
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("wa");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(all(a));

	bool ok = false;
	for (int i = 0; i + 2 < n; ++i) {
		if (a[i + 2] < a[i] + a[i + 1]) {
			ok = true;
		}
	}

	cout << (ok ? "YES\n" : "NO\n");

}