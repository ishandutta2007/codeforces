#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int Q, N;
int arr[101];
int main() {
	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i=0; i<N; i++) {
			int x; cin >> x;
			int cnt = 0;
			while (x) {
				x/=2; ++cnt;
			}
			arr[cnt]++;
		}

		for (int i=0; i<=11; i++) {
			arr[i+1] += arr[i]/2;
		}

		if (arr[12] >= 1) cout << "YES\n";
		else cout << "NO\n";

		memset(arr, 0, sizeof arr);
	}
}