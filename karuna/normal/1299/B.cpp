#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
pll A[100010];

int ccw(pll a, pll b) {
	ll t = a.va * b.vb - a.vb * b.va;
	return (t>0) - (t<0);
}
ll dist(pll a, pll b) {
	return (b.va-a.va)*(b.va-a.va) + (b.vb-a.vb)*(b.vb-a.vb);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> A[i].va >> A[i].vb;
	}
	A[N] = A[0];

	if (N%2 == 1) {
		cout << "NO";
		return 0;
	}
	for (int i=0; i<N/2; i++) {
		pll a = {A[i+1].va - A[i].va, A[i+1].vb - A[i].vb};
		pll b = {A[i+N/2+1].va - A[i+N/2].va, A[i+N/2+1].vb - A[i+N/2].vb};

		int t = ccw(a, b);
		if (t != 0) {
			cout << "NO";
			return 0;
		}
		if (dist(A[i], A[i+1]) != dist(A[i+N/2], A[i+N/2+1])) {
			cout << "NO";
			return 0;
		}

	}
	cout << "YES";
}