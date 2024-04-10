#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int h, g, N, M;
int A[1<<21], B[1<<21], pos[1<<21], des[1<<21];

void init(int idx, int H) {
	if (h == H) {
		des[idx] = idx;
		return;
	}
	init(2*idx, H+1); init(2*idx+1, H+1);
	if (A[2*idx] > A[2*idx+1]) des[idx] = des[2*idx];
	else des[idx] = des[2*idx+1];
}
void update(int idx) {
	if (!A[2*idx] && !A[2*idx+1]) {
		A[idx] = 0;
		return;
	}
	int t;
	if (A[2*idx] > A[2*idx+1]) {
		t = A[2*idx];
		update(2*idx);
	}
	else {
		t = A[2*idx+1];
		update(2*idx+1);
	}

	A[idx] = t;
	pos[t] = idx;
	if (!A[2*idx] && !A[2*idx+1]) des[idx] = idx;
	else if (A[2*idx] > A[2*idx+1]) des[idx] = des[2*idx];
	else des[idx] = des[2*idx+1];
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		cin >> h >> g;
		N = 1<<h; M = 1<<g;

		ll sum = 0;
		for (int i=1; i<N; i++) {
			cin >> A[i];
			B[i] = A[i]; pos[A[i]] = i; sum += A[i];
		}
		init(1, 1);
		sort(B+1, B+N, greater<int>());

		vector<int> ans;
		for (int i=1; i<N; i++) {
 			if (des[pos[B[i]]] < M) continue;
			update(pos[B[i]]);
			ans.push_back(pos[B[i]]);
			sum -= B[i];
		}
		cout << sum << '\n';
		for (int x : ans) cout << x << ' ';
		cout << '\n';

		for (int i=1; i<N; i++) {
			A[i] = B[i] = pos[i] = des[i] = 0;
		}
	}
}