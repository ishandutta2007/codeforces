#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int inf = 1e9;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;

	int bestK = inf, bestPos = -1;

	for (int i = 0; i + sz(s) - 1 < sz(t); ++i) {
		int cnt = 0;
		for (int j = 0; j < sz(s); ++j) {
			if (s[j] != t[i + j]) {
				++cnt;
			}
		}
		if (cnt < bestK) {
			bestK = cnt;
			bestPos = i;
		}
	}

	cout << bestK << "\n";
	for (int j = 0; j < sz(s); ++j) {
		if (s[j] != t[bestPos + j]) {
			cout << j + 1 << " ";
		}
	}
	cout << "\n";

}