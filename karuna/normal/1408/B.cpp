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
		int N, K; cin >> N >> K;
		int A[101];
		for (int i=0; i<N; i++) cin >> A[i];

		if (K == 1) {
			bool flag = false;
			for (int i=0; i<N-1; i++) if (A[i] != A[i+1]) {
				cout << "-1\n";
				flag = true;
				break;
			}
			if (!flag) cout << "1\n";
		}
		else {
			int x = 1;
			for (int i=0; i<N-1; i++) if (A[i] != A[i+1]) x++;

			cout << 1 + (max(0, x - K) + K - 2)/ (K-1) << '\n';
		}
	}
}