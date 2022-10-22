#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 998244353;

int N, K;
int A[200020];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	for (int i=1; i<=N; i++) cin >> A[i];

	ll ans = 1, c = 0, p = 0;
	for (int i=1; i<=N; i++) {
		if (A[i] <= N-K) continue;
		if (p!=0) ans = ans * (i-p)%mod;
		c += A[i];
		p = i;
	}
	cout << c << ' ' << ans;
}