#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

	//freopen("input.txt", "r", stdin);
	//ifstream cin("input.txt");

    //ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	int prev = k;
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		v[i] = a;
		if (a + prev < k) {
			ans += k - (a + prev);
			v[i] += k - (a + prev);
		}
		prev = v[i];
	}

	cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		cout << v[i] << " ";
	}
	cout << "\n";

}