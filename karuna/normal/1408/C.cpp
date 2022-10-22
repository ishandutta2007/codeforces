#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const long double eps = 1e-8;

int N, L;
int A[100010];
vector< pair<long double, int> > S, E;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cout.precision(20);

	int T; cin >> T;
	while (T--) {
		cin >> N >> L;
		for (int i=0; i<N; i++) cin >> A[i];

		S.emplace_back(0, 0);
		E.emplace_back(0, L);

		for (int i=0; i<N; i++) {
			S.emplace_back(S.back().va + (A[i] - S.back().vb)/(long double)(i+1), A[i]);
		}
		for (int i=N-1; i>=0; i--) {
			E.emplace_back(E.back().va + (E.back().vb - A[i])/(long double)(N-i), A[i]);
		}

		long double lo = 0, hi = 2e9;
		while (abs(hi - lo) > eps) {
			long double mid = (lo+hi)/2;
			int a = lower_bound(S.begin(), S.end(), pair<long double, int>(mid, 0)) - S.begin() - 1;
			int b = lower_bound(E.begin(), E.end(), pair<long double, int>(mid, 0)) - E.begin() - 1;

			long double p1 = S[a].vb + (mid - S[a].va)*(a+1);
			long double p2 = E[b].vb - (mid - E[b].va)*(b+1);

			if (abs(lo-hi) < eps) break;
			if (p1 < p2+eps) lo = mid;
			else hi = mid;
		}

		cout << lo << '\n';
		S.clear(); E.clear();
	}
}