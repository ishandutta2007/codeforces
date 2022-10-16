#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
using namespace std;

#define mod NE_mod
#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

void solve() {
	int n, U, R, D, L;
	cin >> n >> U >> R >> D >> L;

	int u, r, d, l;

	for (int i1 = 0; i1 < 2; i1++) {
		for (int i2 = 0; i2 < 2; i2++) {
			for (int i3 = 0; i3 < 2; i3++) {
				for (int i4 = 0; i4 < 2; i4++) {
					u = 0, r = 0, d = 0, l = 0;
					if (i1) {
						u++;
						l++;
					}
					if (i2) {
						u++;
						r++;
					}
					if (i3) {
						d++;
						r++;
					}
					if (i4) {
						d++;
						l++;
					}

					if (u > U) {
						continue;
					}
					if (d > D) {
						continue;
					}
					if (l > L) {
						continue;
					}
					if (r > R) {
						continue;
					}

					if (n - 2 < max(max(U - u, D - d), max(L - l, R - r))) {
						continue;
					}
					cout << "Yes\n";
					return;
				}
			}
		}
	}
	cout << "No\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}