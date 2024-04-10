#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5+1;
int N, K;
ll A[MAX], B[MAX];

ll mypow(ll a, ll x) {
	ll ret = 1;
	while (x) {
		if (a >= MAX || ret >= MAX) return MAX;
		if (x&1) ret = ret*a;
		a = a*a; x/=2;
	}
	return ret;
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> K;
	for (int i=0; i<N; i++) {
		int x; cin >> x; A[x]++;
	}

	for (int i=1; i<MAX; i++) B[i] = 1;

	for (ll i=1; i<MAX; i++) {
		ll x = i;
		for (ll j=2; j*j<=x; j++) {
			int cnt = 0;
			while (x%j == 0) { x/=j; ++cnt; }

			bool flag = true;
			for (int k=0; k<(30*K-cnt)%K; k++) {
				B[i] = B[i]*j;
				if (B[i] >= MAX) { flag = false; break; }
			}
			if (!flag) {
				B[i] = -1; x = 1; break;
			}
		}

		if (x == 1) continue;
		for (int j=0; j<K-1; j++) {
			B[i] = B[i]*x;
			if (B[i] >= MAX) {
				B[i] = -1; break;
			}
		}
	}

	ll ans = 0;
	for (int i=MAX-1; i>0; i--) {
		if (A[i] == 0) continue;
		if (B[i] == -1) continue;

		for (int j=1; B[i]*mypow(j, K)<=i; j++) {
			if (B[i]*mypow(j, K) == i) {
				ans += A[i]*(A[i]-1)/2;
			}
			else ans += A[i]*A[B[i]*mypow(j, K)];
		}
	}

	cout << ans;
}