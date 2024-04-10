#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int repr[65];
int len;

ull dp[11][65][1024];

ull solve(ull n, int b) {
	if (n == 0) {
		return 0;
	}
	// predstavi
	len = 0;
	while (n > 0) {
		repr[len] = n % b;
		n /= b;
		len++;
	}

	/*
	cerr << "repr ";
	for (int i=0; i<len; i++) {
		cerr << repr[i];
	}
	cerr << '\n';
	*/

	// resi
	int mask_so_far = 0;
	ull sol = 0;

	for (int i=len-1; i>=0; i--) {
		// od 1 do cifra-1
		int start = i == len-1 ? 1 : 0;

		for (int j=start; j<repr[i]; j++) {
			sol += dp[b][i][mask_so_far ^ (1 << j)];
		}

		mask_so_far ^= (1 << repr[i]);
	}

	sol += dp[b][0][mask_so_far];

	for (int i=0; i<len-1; i++) {
		for (int dig=1; dig<b; dig++) {
			sol += dp[b][i][1 << dig];
		}		
	}	

	return sol;
}

void calc_dp() {
	for (int b=2; b<=10; b++) {
		dp[b][0][0] = 1;
		for (int len=1; len<65; len++) {
			for (int mask=0; mask<1024; mask++) {
				for (int dig=0; dig<b; dig++) {
					int numask = mask ^ (1 << dig);
					dp[b][len][numask] += dp[b][len-1][mask];					
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	calc_dp();

	int q;
	cin >> q;

	while (q--) {
		int b;
		ull l, r;
		cin >> b >> l >> r;
		cout << (solve(r, b) - solve(l-1, b)) << '\n';
	}
}