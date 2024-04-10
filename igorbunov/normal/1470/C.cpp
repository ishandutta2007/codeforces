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

void DEB() {
	int n = 50;
	int k = 100;
	int bad = 1;
	vector<int> arr(n, k);
	cout << "Time 0:  ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int _ = 1; _ < 10; _++) {
		vector<int> arr1(n);
		for (int i = 0; i < n; i++) {
			if (i == bad) {
				arr1[(i + 1) % n] += arr[i];
			} else {
				arr1[(i - 1 + n) % n] += arr[i] / 2;
				arr1[(i + 1) % n] += (arr[i] + 1) / 2;
			}
		}
		arr = arr1;
		cout << "Time: " << _ << "  ";
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

vector<int> arr;
int n, k;
int bad = 0;
int ask(int ind) {
	cout << "? " << ind + 1 << endl;
	/*vector<int> arr1(n);
	for (int i = 0; i < n; i++) {
		if (i == bad) {
			arr1[(i + 1) % n] += arr[i];
		} else {
			arr1[(i - 1 + n) % n] += arr[i] / 2;
			arr1[(i + 1) % n] += (arr[i] + 1) / 2;
		}
	}
	arr = arr1;
	return arr[ind];*/
	int val;
	cin >> val;
	return val;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	arr.resize(n, k);
	for (int i = 0; i < 325; i++) {
		int val = ask(0);
	}
	int now = 0;
	int need_ind = -1;
	int need_val = -1;
	for (int i = 0; i < 320; i++) {
		int val = ask(now);
		int val1 = ask((now + 1) % n);
		if (val != k) {
			need_ind = now;
			need_val = val;
			break;
		}
		if (val1 != k) {
			need_ind = (now + 1) % n;
			need_val = val1;
			break;
		}
		now += 320;
		now %= n;
	}
	/*cout << need_ind << " " << need_val << endl;
	for (int i = 0; i < n; i++) {
		cout << i << " " << arr[i] << endl;
	}*/
	//cout << need_ind << " " << need_val << endl;
	if (need_val < k) {
		int now = need_ind;
		int val = need_val;
		for (int i = 30; i >= 0; i--) {
			if ((1 << i) >= n) {
				continue;
			}
			int val1 = ask((now + (1 << i)) % n);
			if (val1 <= val) {
				now = (now + (1 << i)) % n;
				val = val1;
			}
		}
		cout << "! " << (now + 1) % n + 1 << endl;
	} else {
		int now = need_ind;
		int val = need_val;
		for (int i = 30; i >= 0; i--) {
			if ((1 << i) >= n) {
				continue;
			}
			int val1 = ask((now - (1 << i) + 2 * n) % n);
			if (val1 >= val) {
				now = (now - (1 << i) + 2 * n) % n;
				val = val1;
			}
		}
		cout << "! " << (now - 1 + n) % n + 1 << endl;
	}
}