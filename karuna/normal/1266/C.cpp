#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int R, C;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> R >> C;

	if (R==1 && C==1) {
		cout << 0;
		return 0;
	}

	if (C==1) {
		for (int i=1; i<=R; i++) cout << i+1 << '\n';
		return 0;
	}

	for (int i=1; i<=R; i++) {
		for (int j=1; j<=C; j++) {
			cout << i*(R+j) << ' ';
		}
		cout << '\n';
	}
}