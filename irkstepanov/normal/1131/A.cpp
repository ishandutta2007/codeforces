#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;

	int ans;
	if (w1 == w2) {
		ans = 2 * (h1 + h2) + 2 * w1 + 4;
	} else {
		ans = 2 * (h1 + h2) + 2 * w1 + 4;
	}

	cout << ans << "\n";
	

}