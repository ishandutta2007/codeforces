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

//309810XU
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"


void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	set<int> kek;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int val = abs(arr[i] - arr[j]);
			if (val != 0) {
				kek.insert(val);
			}
		}
	}
	cout << kek.size() << endl;
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