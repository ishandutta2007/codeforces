#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int B = 256;
const int NB = 512;
const int M = 998244353;

void ad(int& x, int y) {
	x += y;
	if (x >= M)
		x -= M;
}

int n, k;
int a[100005], jmp[100005], seen[100005];
int dp[200005];
int b[200005];
int sdp[NB][2*B+1];
int sb[NB];

void setb(int i, int v) {
	int j = i / B;
	int delta = v - b[i];
	sb[j] += delta;
	b[i] += delta;
	int l = j*B;
	int r = l + B;
	int f = 0;
	fill(sdp[j], sdp[j] + 2*B+1, 0);
	for (int i=r-1; i>=l; i--) {
		f += b[i];
		ad(sdp[j][f+B], dp[i]);
	}
	for (int i=0; i<2*B; i++)
		ad(sdp[j][i+1], sdp[j][i]);
}

int gdp() {
	int v = 0, f = 0;
	for (int j=NB-1; j>=0; j--) {
		int idx = k - f;
		if (idx > B)
			idx = B;
		if (idx >= -B)
			ad(v, sdp[j][idx+B]);
		f += sb[j];
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		jmp[i] = seen[a[i]];
		seen[a[i]] = i;
	}

	dp[0] = 1;
	setb(0, 0);

	for (int i=1; i<=n; i++) {
		if (jmp[i]) {
			if (jmp[jmp[i]]) {
				setb(jmp[jmp[i]] - 1, 0);
			}
			setb(jmp[i]-1, -1);
		}
		setb(i-1, 1);
		dp[i] = gdp();
		setb(i, 0);
	}

	cout << dp[n] << '\n';
}