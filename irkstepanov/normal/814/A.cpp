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

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	sort(all(b));

	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			a[i] = b.back();
			b.pop_back();
		}
	}

	bool ok = false;
	for (int i = 1; i < n; ++i) {
		if (a[i] <= a[i - 1]) {
			ok = true;
		}
	}

	cout << (ok ? "Yes\n" : "No\n");

}