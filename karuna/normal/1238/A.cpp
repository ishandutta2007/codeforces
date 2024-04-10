#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T;
ll X, Y;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> X >> Y;
		cout << (X-Y!=1 ? "YES" : "NO") << '\n';
	}
}