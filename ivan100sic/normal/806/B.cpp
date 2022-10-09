#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n;
int vas[5], pet[5], solvers[5];
int max_delta[5][5005];

int get_kat(int p, int q) {
	// p / q > 1 / 2
	if (2*p > q) {
		return 1;
	} else if (4*p > q) {
		return 2;
	} else if (8*p > q) {
		return 3;
	} else if (16*p > q) {
		return 4;
	} else if (32*p > q) {
		return 5;
	} else {
		return 6;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<5; i++) {
		cin >> vas[i];
		if (vas[i] != -1) {
			solvers[i]++;
		} else {
			vas[i] = 250;
		}
	}
	for (int i=0; i<5; i++) {
		cin >> pet[i];
		if (pet[i] != -1) {
			solvers[i]++;
		} else {
			pet[i] = 250;
		}
	}
	for (int i=2; i<n; i++) {
		for (int j=0; j<5; j++) {
			int x;
			cin >> x;
			if (x != -1) {
				solvers[j]++;
			}
		}
	}

	const int MAX_SOL = 5000;

	for (int x=0; x<=MAX_SOL; x++) {	
		for (int i=0; i<5; i++) {
			max_delta[i][x] = -1e8;
			for (int y=0; y<=x; y++) {
				if (y > 0 && vas[i] == 250) {
					break;
				}
				int dif = (pet[i] - vas[i]) * get_kat(solvers[i] + y, n + x);
				max_delta[i][x] = max(max_delta[i][x], dif);
			}
			// cerr << x << ' ' << i << ' ' << max_delta[i][x] << '\n';
		}
	}

	for (int x=0; x<=MAX_SOL; x++) {
		int dif = 0;
		for (int i=0; i<5; i++) {
			dif += max_delta[i][x];
		}
		if (dif > 0) {
			cout << x;
			return 0;
		}
	}
	cout << -1;

}