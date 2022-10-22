#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t, N;
int M[2000010];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		string S; cin >> S;
		N = S.size();

		int p = 0;
		while (p < N-1-p && S[p] == S[N-1-p]) ++p;

		string T = "";
		for (int i=p; i<N-p; i++) {
			T += S[i];
			if (i != N-p-1) T += '#';
		}
		N = T.size();
		for (int i=0; i<N; i++) M[i] = 0;

		if (T.empty()) {
			cout << S << '\n';
			continue;
		}

		int mx = 0, mxp = 0;
		for (int i=1; i<N; i++) {
			if (mx >= i) M[i] = min(mx-i, M[2*mxp-i]);
			while (i + M[i] < N && i - M[i] >= 0 && T[i + M[i]] == T[i - M[i]]) {
				++M[i];
			}
			--M[i];
			if (i + M[i] > mx) mx = i + M[i], mxp = i;
		}


		int mxl = 0, mxr = N;
		for (int i=0; i<N; i++) {
			if (i - M[i] == 0) mxl = i + M[i];
		}
		for (int i=N-1; i>=0; i--) {
			if (i + M[i] == N-1) mxr = i - M[i];
		}

		string ans = "";
		for (int i=0; i<p; i++) ans += S[i];

		string L = "", R = "";
		for (int i=0; i<=mxl; i++) if (T[i] != '#') L += T[i];
		for (int i=mxr; i<N; i++) if (T[i] != '#') R += T[i];


		cout << ans; reverse(ans.begin(), ans.end());
		if (!L.empty() || !R.empty()) {
			if (L.size() >= R.size()) cout << L;
			else cout << R;
		}
		cout << ans << '\n';

	}
}