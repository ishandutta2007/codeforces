#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

// n = 4:
// (1, 1), (1, 2), (1, 3)
// (2, 1), (2, 2), (2, 4)
// (3, 1), (3, 3)
// (4, 1), (4, 4)

// so for i with 2*i > n, we get 1
// for i with 2*i <= n, but 3*i > n, we get 3
// for i with 3*i <= n, we get 5

// n + 2*floor(n/2) + 2*floor(n/3)

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll out = n + 2*(n/2) + 2*(n/3);
		cout << out << endl;
	}
}