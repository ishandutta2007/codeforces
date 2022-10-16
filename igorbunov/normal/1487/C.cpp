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

#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"


void solve() {
	int n;
	cin >> n;
	vector<int> kek(n);
	if (n == 2) {
		cout << 0 << " ";
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (n % 2 == 0 && j - i == n / 2) {
					cout << 0 << " ";
					continue;
				}
				if (j - i <= n / 2) {
					kek[i - 1]++;
					cout << 1 << " ";
				} else {
					kek[j - 1]++;
					cout << -1 << " ";
				}
			}
		}
	}
	cout << endl;
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