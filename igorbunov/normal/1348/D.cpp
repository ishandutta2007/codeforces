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
	int n;
	cin >> n;

	int a = 1;
	int cnt = 0;

	//cout << "TEST " << n << endl;

	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	if (n == 2) {
		cout << 1 << endl << 0 << endl;
		return;
	}
	int ans = 0;
	while (cnt < 31) {
		cnt++;
		a *= 2;

		if (n + 1 == a) {
			cout << cnt - 1 << endl;
			for (int i = 0; i < cnt - 1; i++) {
				cout << (1 << i) << " ";
			}
			cout << endl;
			return;
		}
		if (a >= n + 1) {
			ans = cnt;
			break;
		}
	}

	ans--;
	cout << ans << endl;

	int now = 1;
	int now1 = 1;
	vector<int> kek;

	for (int i = 0; i < ans - 2; i++) {
		cout << (1 << i) << " ";
		kek.push_back((1 << i));
		now1 *= 2;
		now += now1;
	}

	int max1 = now1;
	n -= now1 * 2;
	n -= now;

	//cout << endl << n << " -" << endl;

	int a1 = min(now1, (n + 1) / 3);
	int b1 = n - (2 * a1);

	kek.push_back(a1);
	kek.push_back(b1);



	cout << a1 << " ";
	cout << b1 << " ";

	cout << endl;

	n += now1 * 2;
	n += now;
	now = 1;
	now1 = 1;


	for (int i = 0; i < ans; i++) {
		if (kek[i] > now1) {
			cout << "ERROR";
			return;
		}
		now1 += kek[i];
		now += now1;
	}

	if (now != n) {
		cout << now << " " << "ERROR1";
	}


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