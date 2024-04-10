#include<bits/stdc++.h>
using namespace std;


int main() {
	long long N; cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	for (long long p = 2; ; p++) {
		if (p * p > N) p = N;
		if (N % p == 0) {
			//ll v = N;
			while (N % p == 0) N /= p;
			if (N == 1) {
				cout << p << '\n';
			}else {
				cout << 1 << '\n';
			}
			return 0;
		}
	}
	return 0;
}