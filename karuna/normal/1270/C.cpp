#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll A[100010];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		cin >> N;
		for (int i=0; i<N; i++) cin >> A[i];

		ll sum=0, x=0;
		for (int i=0; i<N; i++) {
			sum += A[i];
			x ^= A[i];
		}

		cout << 2 << '\n';
		cout << x << ' ' << sum+x << '\n';
	}
}