#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e5+1;
int N, M;
int A[MAX], B[5*MAX], dp1[MAX], dp2[MAX];
int L[MAX], R[MAX];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i=1; i<=M; i++) cin >> A[i];
	for (int i=1; i<=N; i++) L[i] = max(1, i-1);
	for (int i=1; i<=N; i++) R[i] = min(N, i+1);

	for (int i=M; i>0; i--) {
		if (B[A[i]+i+1] != 0) dp1[i] = dp1[B[A[i]+i+1]];
		else dp1[i] = max(1, A[i]-M+i);
		B[A[i]+i] = i;
	}

	for (int i=1; i<=N; i++) {
		if (B[L[i]+1] != 0) L[i] = dp1[B[L[i]+1]];
		else L[i] = max(1, L[i]-M);
	}

	for (int i=1; i<=2*N+M; i++) B[i] = 0;
	for (int i=M; i>0; i--) {
		if (B[A[i]-i-1+M+N] != 0) dp2[i] = dp2[B[A[i]-i-1+M+N]];
		else dp2[i] = min(N, A[i]+M-i);
		B[A[i]-i+M+N] = i;
	}

	for (int i=1; i<=N; i++) {
		if (B[R[i]+M+N-1] != 0) R[i] = dp2[B[R[i]+M+N-1]];
		else R[i] = min(N, R[i]+M);
	}

	/*
	for (int i=1; i<=M; i++) cout << dp1[i] << ' ';
	cout << '\n';
	for (int i=1; i<=M; i++) cout << dp2[i] << ' ';
	cout << '\n';

	for (int i=1; i<=N; i++) cout << L[i] << ' ';
	cout << '\n';
	for (int i=1; i<=N; i++) cout << R[i] << ' ';
	*/

	ll ans = 0;
	for (int i=1; i<=N; i++) {
		ans += (ll)R[i]-L[i]+1;
	}
	cout << (N==1 ? 0 : ans);
}