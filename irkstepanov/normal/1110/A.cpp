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

	int b, k;
	cin >> b >> k;

	int r = 0;
	vector<int> a(k);
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
	}

	int deg = 1;
	for (int i = k - 1; i >= 0; --i) {
		int val = a[i] % 2;
		val *= deg;
		r += val;
		deg *= (b % 2);
	}

	if (r % 2 == 0) {
		cout << "even\n";
	} else {
		cout << "odd\n";
	}


}