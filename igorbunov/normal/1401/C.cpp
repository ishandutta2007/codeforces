#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
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

 
//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


//#define int long long
#define endl "\n"

int calc (int a, int b) {
	if (a > b) {
		return a * b;
	}
	if (a == b) {
		return 0;
	}
	if (a < b) {
		return -1 * a * b;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	int a = 1000000000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		a = min(a, arr[i]);
	}
	vector<bool> used(n);
	vector<int> arr1;
	for (int i = 0; i < n; i++) {
		if (arr[i] % a == 0) {
			used[i] = 1;
			arr1.push_back(arr[i]);
		}
	}
	sort(arr1.begin(), arr1.end());
	int ind = 0;
	for (int i = 0; i < n; i++) {
		if (used[i]) {
			arr[i] = arr1[ind];
			ind++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}