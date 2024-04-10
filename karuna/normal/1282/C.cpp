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
typedef pair<ll, ll> pll;

ll M, N, T, a, b;
pll A[200020];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> M;
	while (M--) {
		cin >> N >> T >> a >> b;
		for (ll i=1; i<=N; i++) cin >> A[i].vb;
		for (ll i=1; i<=N; i++) cin >> A[i].va;

		sort(A+1, A+N+1);

		vector<ll> v;
		v.push_back(0);
		ll ca=0, cb=0;
		for (ll i=1; i<=N; i++) {
			if (A[i].vb) cb++;
			else ca++;
			v.push_back(A[i].va);
		}
		v.push_back(T+1);

		ll i=1, ans=0, s=0;
		for (int cur=0; cur+1<v.size(); cur++) {
			while (i<=N && A[i].va == v[cur]) {
				if (A[i].vb) s += b, --cb;
				else s += a, --ca;
				++i;
			}
			if (s >= v[cur+1]) continue;

			ll ex=0, rmn = v[cur+1]-1-s;
			ex += max(0LL, min(ca, rmn/a)); rmn -= a*ex;
			ex += max(0LL, min(cb, rmn/b)); rmn -= b*ex;

			ans = max(ans, i-1+ex);
		}

		cout << ans << '\n';
	}
}