#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll A[1000010];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		scanf("%lld", &A[i]);
	}

	vector<pll> v;
	v.emplace_back(A[1], 1);
	for (int i=2; i<=N; i++) {
		pll cur = {A[i], 1};
		while (!v.empty()) {
			pll t = v.back();
			if (t.va * cur.vb < t.vb * cur.va) break;
			cur.va += t.va; cur.vb += t.vb;
			v.pop_back();
		}
		v.push_back(cur);
	}

	for (pll x : v) {
		for (ll i=0; i<x.vb; i++) printf("%.9lf\n", x.va / (double)x.vb);
	}
}