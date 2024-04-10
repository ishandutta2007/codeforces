#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int Q, N, R;
int A[101010];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> Q;
	while (Q--) {
		cin >> N >> R;
		for (int i=0; i<N; i++) cin >> A[i];

		sort(A, A+N, [](int a, int b) { return a>b; });

		int ans = 0;
		for (int i=0; i<N; i++) {
			while (i<N && A[i] == A[i+1]) ++i;
			if (A[i]-ans*R<=0) break;
			++ans;
		}

		cout << ans << '\n';
	}
}