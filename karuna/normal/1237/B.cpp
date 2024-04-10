#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, x, cnt;
int A[100001], B[100001];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i=0; i<N; i++) { cin >> x; A[x] = i; }
	for (int i=0; i<N; i++) cin >> B[i];

	for (int i=0; i<N; i++) B[i] = A[B[i]];

	int mn = N;
	for (int i=N-1; i>=0; i--) {
		if (mn > B[i]) mn = B[i];
		else ++cnt;
	}

	cout << cnt;
}