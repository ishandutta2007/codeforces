#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;

	while (q--) {
		int a;
		cin >> a;
		int k = 0;
		while ((1 << (k + 1)) <= a) {
			++k;
		}
		if (a == (1 << (k + 1)) - 1) {
			int biggest = 1;
			for (int d = 2; d * d <= a; ++d) {
				if (a % d == 0) {
					biggest = a / d;
					break;
				}
			}
			cout << biggest << "\n";
		} else {
			cout << (1 << (k + 1)) - 1 << "\n";
		}
	}

}