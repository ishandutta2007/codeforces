/*
#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<pii, pii> mp;

const int sz = 100;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist1(1, 5000);
	uniform_int_distribution<> dist2(1, 10000);

	while (mp.size()<10000) {
		int x = dist1(gen), y = dist1(gen);
		x^y
		if (x==y) continue;
		if (x>y) swap(x, y);
		mp[{x^y, (x+y)%5000}] = {dist2(gen), dist2(gen)};
	}

	cout << 5000 << ' ' << 10000 << '\n';
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if ((it->va).va == (it->va).vb) continue;
		cout << (it->va).va << ' ' << (it->va).vb << ' ' << (it->vb).va << ' ' << (it->vb).vb << '\n';
	}
}
*/

#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll N, P, K;
ll A[200020], B[200020];
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> N >> P >> K;
		for (int i=1; i<=N; i++) cin >> A[i];
		sort(A+1, A+N+1);

		for (int i=1; i<=N; i++) B[i] = 0;

		int ans = 0;
		for (int i=1; i<K; i++) {
			B[i] = B[i-1] + A[i];
			if (B[i] <= P) ans = i;
		}

		for (int i=K; i<=N; i++) {
			int idx = (i-1)%K+1;
			B[idx] += A[i];
			if (B[idx] <= P) ans = i;
		}

		cout << ans << '\n';
	}
}