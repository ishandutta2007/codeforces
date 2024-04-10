#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int fsf[1000005];

void sito() {
	for (long long i=2; i<1000005; i++) {
		if (fsf[i] == 0) {
			fsf[i] = i;
			for (long long j=i*i; j<1000005; j += i) {
				if (fsf[j] == 0) {
					fsf[j] = i;
				}
			}
		}		
	}
}

vector<int> fvec(int x) {
	vector<int> v;
	int q = 1, b = 0;
	while (x > 1) {
		int p = fsf[x];
		if (p == q) {
			b++;
		} else {
			v.push_back(b);
			b = 1;
			q = p;
		}
		x /= p;
	}
	if (b > 0) {
		v.push_back(b);
	}

	return v;
}

int b[1000005][20];

const int MOD = 1'000'000'007;

void init_brojka() {
	b[0][0] = 1;
	for (int i=1; i<20; i++) {
		b[0][i] = 2;
	}

	for (int i=1; i<=1000000; i++) {
		b[i][0] = b[i-1][0];
		for (int j=1; j<20; j++) {
			b[i][j] = b[i][j-1] + b[i-1][j];
			if (b[i][j] >= MOD) {
				b[i][j] -= MOD;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	sito();
	init_brojka();

	int q;
	cin >> q;
	while (q--) {
		int x, n;

		cin >> n >> x;

		auto vx = fvec(x);

		int sol = 1;

		for (int x : vx) {
			sol = b[n][x] * 1ll * sol % MOD;
		}

		cout << sol << '\n';

	}


}