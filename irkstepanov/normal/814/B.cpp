#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

mt19937 rr(random_device{}());

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		--b[i];
	}

	for (int i = 0; i < n; ++i) {
		vector<char> used(n, false);
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			used[a[j]] = true;
		}
		int f = -1;
		bool ok = true;
		for (int j = 0; j < n; ++j) {
			if (!used[j]) {
				if (f == -1) {
					f = j;
					continue;
				} else {
					ok = false;
				}
			}
		}
		if (!ok) {
			continue;
		}
		vector<int> p(n);
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				p[j] = f;
			} else {
				p[j] = a[j];
			}
		}
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (b[j] != p[j]) {
				++cnt;
			}
		}
		if (cnt == 1) {
			for (int j = 0; j < n; ++j) {
				cout << p[j] + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}

}