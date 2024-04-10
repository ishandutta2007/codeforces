#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int n;
	cin >> n;

	map<int, int> mapa;
	string s;
	cin >> s;

	int x = 0, y = 0;
	mapa[0] = -1;
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			++x;
		} else {
			++y;
		}
		if (mapa.count(y - x)) {
			ans = max(ans, i - mapa[y - x]);
		} else {
			mapa[y - x] = i;
		}		
	}

	cout << ans << "\n";

}