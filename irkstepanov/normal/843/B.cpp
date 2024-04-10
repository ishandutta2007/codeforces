#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

mt19937 rr(998244353);

int main() {

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n, start, x;
	cin >> n >> start >> x;

	vector<int> val(n + 1, -1), nx(n + 1, -1);
	cout << "? " << start << "\n";
	cout.flush();
	cin >> val[start] >> nx[start];

	for (int i = 0; i < 999; ++i) {
		int pos = rr() % n + 1;
		if (val[pos] != -1) {
			continue;
		}
		cout << "? " << pos << "\n";
		cout.flush();
		cin >> val[pos] >> nx[pos];
	}

	if (val[start] >= x) {
		cout << "! " << val[start];
		cout.flush();
		return 0;
	}

	int best = start;
	for (int i = 1; i <= n; ++i) {
		if (val[i] != -1 && val[i] > val[best] && val[i] < x) {
			best = i;
		}
	}

	while (true) {
		best = nx[best];
		if (best == -1) {
			cout << "! -1\n";
			cout.flush();
			return 0;
		}
		if (val[best] == -1) {
			cout << "? " << best << "\n";
			cout.flush();
			cin >> val[best] >> nx[best];
		}
		if (val[best] < x) {
			continue;
		} else {
			cout << "! " << val[best] << "\n";
			cout.flush();
			return 0;
		}
	}

}