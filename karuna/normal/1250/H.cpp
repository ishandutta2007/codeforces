#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T;
int n, x, a, b;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n >> x >> a >> b;
		int ans = abs(b-a);
		cout << min(n-1, ans+x) << '\n';
	}
}