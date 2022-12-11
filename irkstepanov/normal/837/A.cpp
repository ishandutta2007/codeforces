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
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");
	
	int n;
	cin >> n;

	int ans = 0;
	string s;
	
	while (cin >> s) {
		int cnt = 0;
		for (int i = 0; i < sz(s); ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				++cnt;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	
}