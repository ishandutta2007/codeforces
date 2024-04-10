#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N;
int A[400040];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i=0; i<N; i++) cin >> A[i];

		int g=0, s=0, b=0;
		int gp=0, sp=0, bp=N-1;
		while (bp>0 && bp+1>N-bp-1 || A[bp] == A[bp+1]) --bp;
		while (gp<N && A[gp] == A[gp+1]) ++gp;

		sp = gp+1;
		while (sp<N && (A[sp] == A[sp+1] || gp+1 >= sp-gp)) ++sp;

		g = gp+1; s= sp-gp; b = bp-sp;

		if (g<=0 || s<=0 || b<=0 || g>=s || g>=b) cout << "0 0 0\n";
		else cout << g << ' ' << s << ' ' << b << '\n';
	}

}