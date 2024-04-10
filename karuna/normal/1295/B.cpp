#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		int N, X; cin >> N >> X;
		string s; cin >> s;

		int c = 0, mx = -N, mn = N;
		ll p = 0;
		for (int i=0; i<=N; i++) {
			if (i == 0) 1+1;
			else if (s[i-1] == '0') c++;
			else c--;
			mx = max(mx, c);
			mn = min(mn, c);
		}

		int k = 0;
		for (int i=0; i<N; i++) {
			if (i == 0) 1+1;
			else if (s[i-1] == '0') k++;
			else k--;
			if (c == 0) {
				if (k == X) ++p;
			}
			else if (c<0) {
				if (k>=X && (k-X)%abs(c) == 0) ++p;
			}
			else {
				if (k<=X && (X-k)%c == 0) ++p;
			}
		}

		if (c == 0) {
			if (p) cout << "-1\n";
			else cout << "0\n";
			continue;
		}

		cout << p << '\n';
	}
}