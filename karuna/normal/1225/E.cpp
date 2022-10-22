#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
ll N, M;
ll cntd[2010][2010], cntr[2010][2010];
ll dp1[2010][2010], dp2[2010][2010];
string S[2010];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (ll i=0; i<N; i++) cin >> S[i];

	if (S[N-1][M-1] == 'R') {
		cout << 0;
		return 0;
	}

	for (ll i=N-2; i>=0; i--) for (ll j=0; j<M; j++) {
		if (S[i+1][j] == 'R') cntd[i][j] = cntd[i+1][j] + 1;
		else cntd[i][j] = cntd[i+1][j];
	}

	for (ll j=M-2; j>=0; j--) for (ll i=0; i<N; i++) {
		if (S[i][j+1] == 'R') cntr[i][j] = cntr[i][j+1] + 1;
		else cntr[i][j] = cntr[i][j+1];

	}

	dp1[N-1][M-1] = dp2[N-1][M-1] = 1;
	for (ll i=N-1; i>=0; i--) {
		for (ll j=M-1; j>=0; j--) {
			if (i==N-1 && j==M-1) continue;
			dp1[i][j] = ((dp1[i][j+1]+dp2[i+1][j])%mod + mod-dp2[N-cntd[i][j]][j])%mod;
			dp2[i][j] = ((dp2[i+1][j]+dp1[i][j+1])%mod + mod-dp1[i][M-cntr[i][j]])%mod;
		}
	}

	if (N==1 && M==1) cout << 1;
	else cout << (((dp1[0][0]+dp2[0][0])%mod + mod-dp1[0][1])%mod + mod-dp2[1][0])%mod;
}