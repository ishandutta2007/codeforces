#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int A[200020], B[200020];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i=1; i<=N; i++) cin >> B[i];

	int x = 0;
	for (int i=1; i<=N; i++) {
		if (B[i] < 0) cout << B[i]+x << ' ';
		else {
			cout << B[i]+x << ' ';
			x += B[i];
		}
	}
}