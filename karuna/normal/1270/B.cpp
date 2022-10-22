#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int A[200020];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		cin >> N;
		for (int i=0; i<N; i++) cin >> A[i];

		bool flag = false;
		for (int i=0; i+1<N; i++) {
			if (max(A[i], A[i+1]) - min(A[i], A[i+1]) >= 2) {
				flag = true;
				cout << "YES\n";
				cout << i+1 << ' ' << i+2 << '\n';
				break;
			}
		}

		if (!flag) {
			cout << "NO\n";
		}
	}
}