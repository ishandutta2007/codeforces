#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, a, b;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		cin >> N >> a >> b;

		bool flag = false;
		for (int i=0; i<a; i++) {
			int x; cin >> x;
			if (x==N) flag = false;
		}
		for (int i=0; i<b; i++) {
			int x; cin >> x;
			if (x==N) flag = true;
		}

		cout << (flag ? "NO\n" : "YES\n");
	}
}