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


#define int long long
#define endl "\n"

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	map<int, int> kek;
	int cnt = 0;
	vector<int> arr1;
	for (int i = 0; i < n; i++) {
		kek[arr[i]]++;
		if (kek[arr[i]] == 1) {
			cnt++;
			arr1.push_back(arr[i]);
		}
	}

	//cout << cnt << " ";

	if (cnt > k) {
		cout << -1 << endl;;
		return;
	}

	cout << n * k << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << arr1[j % (arr1.size())] << " ";
		}
	}
	cout << endl;
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