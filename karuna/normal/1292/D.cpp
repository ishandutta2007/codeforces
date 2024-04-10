#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int A[5050], F[700][5050], mxp[5050];
bool sieve[5050] = {1, 1};
vector<int> pr;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i=0; i<N; i++) {
		int x; cin >> x; A[x]++;
	}

	for (int i=2; i<5050; i++) {
		if (sieve[i]) continue;
		pr.push_back(i);
		for (int j=2*i; j<5050; j+=i) sieve[j] = true;
	}

	for (int i=1; i<5050; i++) {
		for (int j=0; j<pr.size(); j++) {
			int num = i;
			while (num) F[j][i] += num/pr[j], num /= pr[j];
		}
	}

	ll ans = 0;
	for (int i=0; i<5050; i++) {
		for (int j=0; j<pr.size(); j++) {
			ans += (ll)A[i] * F[j][i];
			if (F[j][i]) mxp[i] = j;
		}
	}
	mxp[0] = mxp[1] = -1;

	bool chk[5050]; memset(chk, false, sizeof chk);
	while (1) {
		int X[700]; memset(X, 0, sizeof X);
		for (int i=0; i<5050; i++){
			if (!chk[i] && mxp[i] != -1) X[mxp[i]] += A[i];
		}

		int x = max_element(X, X+700) - X;
		if (X[x] <= N-X[x]) break;
		ans -= X[x] - (N-X[x]);
		for (int i=0; i<5050; i++) {
			if (!chk[i] && mxp[i] == x) {
				F[x][i]--;
				while (mxp[i]>=0 && F[mxp[i]][i] == 0) --mxp[i];

			}
			else chk[i] = true;
		}
	}
	cout << ans;
}