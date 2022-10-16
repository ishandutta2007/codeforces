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

void solve() {
	int n, w;
	cin >> n >> w;
	vector<int> arr(n);
	int now = 0LL;
	vector<int> inds;
	int need = ((w + 1LL) / 2LL);
	//cout << need;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int c = arr[i];
		if (c > w) {
			continue;
		}
		if (c >= need) {
			if (c > w) {
				exit(1);
			}
			cout << 1 << endl << i + 1 << endl;
			return;
		}
		now += c;
		inds.push_back(i + 1LL);
		if (now >= need) {
			if (now > w) {
				//exit(1);
			}
			int now1 = 0;
			cout << inds.size() << endl;
			for (int j = 0; j < inds.size(); j++) {
				now1 += arr[inds[j] - 1];
				cout << inds[j] << " ";
			}
			//cout << endl;
			//cout << now << " " << now1 << endl;
			if (now != now1) {
				exit(1);
			}
			cout << endl;
			return;
		}
	}
	if (now >= need) {
			if (now > w) {
				//exit(1);
			}
			int now1 = 0;
			cout << inds.size() << endl;
			for (int j = 0; j < inds.size(); j++) {
				now1 += arr[inds[j] - 1];
				cout << inds[j] << " ";
			}
			//cout << endl;
			//cout << now << " " << now1 << endl;
			if (now != now1) {
				exit(1);
			}
			cout << endl << endl;
			return;
		}
	cout << -1 << endl;
}
signed main() {     int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }

}