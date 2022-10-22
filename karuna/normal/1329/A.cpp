#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
int A[100010];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i=1; i<=M; i++) cin >> A[i];

	ll sum = 0;
	for (int i=1; i<=M; i++) {
		sum += A[i];
		if (i+A[i]-1 > N) {
			cout << -1;
			return 0;
		}
	}

	if (sum < N) {
		cout << -1;
		return 0;
	}

	int diff = 0;
	for (int i=1; i<=M; i++) {
		diff = max(diff, i+A[i]-1);
	}
	diff = N - diff;

	int p = 1;
	for (int i=1; i<=M; i++) {
		cout << p << ' ';
		int c = 1;
		while (diff>0 && c < A[i]) --diff, ++c;
		p += c;
	}
}