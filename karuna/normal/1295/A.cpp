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
		int N; cin >> N;
		if (N%2 == 0) {
			for (int i=0; i<N; i+=2) cout << 1;
		}
		else {
			cout << 7;
			for (int i=3; i<N; i+=2) cout << 1;
		}
		cout << '\n';
	}
}