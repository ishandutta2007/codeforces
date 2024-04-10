#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
bool chk[7070];
pll A[7070];
queue<int> q;
vector<pll> sel;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i=0; i<N; i++) cin >> A[i].va;
	for (int i=0; i<N; i++) cin >> A[i].vb;

	for (int i=0; i<N; i++) {
		for (int j=0; j<i; j++) {
			if (A[i].va != A[j].va) continue;

			if (!chk[i]) {
				q.push(i);
				chk[i] = true;
			}
			if (!chk[j]) {
				q.push(j);
				chk[j] = true;
			}
		}
	}

	memset(chk, false, sizeof chk);
	while (!q.empty()) {
		int tmp = q.front(); q.pop();

		if (chk[tmp]) continue;
		chk[tmp] = true;
		sel.push_back(A[tmp]);

		for (int i=0; i<N; i++) {
			if (A[i].va < A[tmp].va && A[tmp].va-A[i].va == (A[i].va^A[tmp].va)) q.push(i);
		}
	}

	ll ans = 0;
	for (auto x : sel) ans += x.vb;

	cout << ans;
}