#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, x, cnt;
int A[202020];
int P[202020];
int main() {
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> x;
		if (x<0) A[i] = 1;
	}

	for (int i=1; i<=N; i++) {
		P[i] = P[i-1] + A[i];
		if (P[i]&1) ++cnt;
	}

	cout << (ll)cnt*(N+1-cnt) << ' ' << (ll)cnt*(cnt-1)/2 + (ll)(N+1-cnt)*(N-cnt)/2;
}