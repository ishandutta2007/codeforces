#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T, N;
int A[200020], idx[200020];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i=1; i<=N; i++) idx[i] = 0;
		for (int i=1; i<=N; i++) cin >> A[i];

		int ans = N+1;
		for (int i=1; i<=N; i++) {
			if (idx[A[i]] == 0) idx[A[i]] = i;
			else {
				ans = min(ans, i-idx[A[i]]+1);
				idx[A[i]] = i;
			}
		}

		if (ans==N+1) cout << "-1\n";
		else cout << ans << '\n';
	}
}