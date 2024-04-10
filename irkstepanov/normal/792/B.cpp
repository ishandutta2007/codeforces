#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> id(n);
	for (int i = 0; i < n; ++i) {
		id[i] = i + 1;
	}

	int ptr = 0;

	while (k--) {
		int a;
		cin >> a;
		a %= sz(id);
		while (a--) {
			++ptr;
			if (ptr == sz(id)) {
				ptr = 0;
			}
		}
		cout << id[ptr] << " ";
		vector<int> alive;
		for (int i = 0; i < sz(id); ++i) {
			if (i != ptr) {
				alive.pb(id[i]);
			}
		}
		id.swap(alive);
		if (ptr == sz(id)) {
			ptr = 0;
		}
	}
	cout << "\n";

}