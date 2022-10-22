#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 3e16;
ll x0, y0, ax, ay, bx, by, xs, ys, T;
vector<pll> A;

ll dist(pll a, pll b) {
	return abs(a.va-b.va) + abs(a.vb-b.vb);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> T;
	A.emplace_back(x0, y0);
	while (x0 < INF && y0 < INF) {
		x0 = ax * x0 + bx;
		y0 = ay * y0 + by;
		A.emplace_back(x0, y0);
	}

	int N; N = A.size();
	ll ans = 0;
	pll st = {xs, ys};
	for (int i=0; i<N; i++) {
		ll d = T, c = 0;
		if (d - dist(st, A[i]) >= 0) {
			d -= dist(st, A[i]);
			++c;
		}
		else continue;

		bool flag = true;
		for (int j=i; j>0; j--) {
			if (d - dist(A[j], A[j-1]) < 0) {
				flag = false;
				break;
			}
			d -= dist(A[j], A[j-1]);
			++c;
		}
		if (!flag) {
			ans = max(ans, c);
			continue;
		}

		if (i != N-1 && d - dist(A[0], A[i+1]) >= 0) {
			d -= dist(A[0], A[i+1]);
			++c;
		}
		else {
			ans = max(ans, c);
			continue;
		}

		for (int j=i+1; j<N-1; j++) {
			if (d - dist(A[j], A[j+1]) < 0) break;
			d -= dist(A[j], A[j+1]);
			++c;
		}
		ans = max(ans, c);
	}

	cout << ans;

}