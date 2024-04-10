#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
ll A[100010];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i=0; i<M; i++) {
		ll x, y, z; cin >> x >> y >> z;
		A[x] -= z;
		A[y] += z;
	}

	priority_queue<pll> pq1, pq2;
	for (int i=1; i<=N; i++) {
		if (A[i]<0) pq1.emplace(A[i], i);
		if (A[i]>0) pq2.emplace(A[i], i);
	}

	vector<pair<pll, ll>> ans;

	while (!pq1.empty() && !pq2.empty()) {
		pll from = pq1.top(); pq1.pop();
		pll to = pq2.top(); pq2.pop();

		if (-from.va <= to.va) {
			if (from.vb != to.vb) ans.push_back({{from.vb, to.vb}, -from.va});
			if (to.va+from.va) pq2.emplace(to.va+from.va, to.vb);
		}
		else {
			if (from.vb != to.vb) ans.push_back({{from.vb, to.vb}, to.va});
			if (to.va+from.va) pq1.emplace(from.va+to.va, from.vb);
		}
	}

	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x.va.va << ' ' << x.va.vb << ' ' << x.vb << '\n';
	}
}