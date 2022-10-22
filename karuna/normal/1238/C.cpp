#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int Q, H, N;
int A[202020];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> Q;
	while (Q--) {
		cin >> H >> N;
		for (int i=0; i<N; i++) cin >> A[i];

		int a=1, b=0, c=0;
		for (int i=1; i<N; i++) {
			if (A[i-1] == A[i]+1) swap(a, b);
			else {
				a=b; ++b;
			}
		}

		int ans;
		if (A[N-1] == 1 || A[N-2] == 1) ans = min(a, b);
		else ans = b;

		cout << ans << '\n';
	}
}