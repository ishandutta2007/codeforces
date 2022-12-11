#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const ld inf = 1e18;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n;
	ld p;
	cin >> n >> p;

	vector<ld> a(n), b(n);
	ld suma = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		suma += a[i];
	}

	if (suma <= p) {
		cout << "-1\n";
		return 0;
	}

	ld lf = 0, rg = inf;
	for (int op = 0; op < 100; ++op) {
		ld t = (rg + lf) / 2;
		ld sump = 0;
		for (int i = 0; i < n; ++i) {
			ld val = t * a[i] - b[i];
			if (val < 0) {
				continue;
			}
			sump += val / t;
		}
		if (sump > p) {
			rg = t;
		} else {
			lf = t;
		}
	}

	cout << fixed;
	cout.precision(12);
	cout << lf << "\n";

}