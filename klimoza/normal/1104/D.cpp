#pragma optimise('O3');
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 1e9 + 7;


int main() {
	while (true) {
		string st;
		cin >> st;
		if (st == "end") break;
		if (st == "mistake") break;
		int cur = -1;
		for (int k = 0; k < 50; k++) {
			string an1;
			cout << "? " << (1 << k) << " " << (1 << (k + 1)) << endl;
			fflush(stdout);
			cin >> an1;
			if (an1 == "e") return 0;
			if (an1 == "x") {
				cur = k;
				break;
			}
		}
		ll l = 1 << cur;
		ll r = (1 << (cur + 1));
		string an;
		while (r - l > 1) {
			ll mid = (r + l) / 2;
			cout << "? " << mid << " " << r << endl;
			fflush(stdout);
			cin >> an;
			if (an == "e") return 0;
			if (an == "x") {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		cout << "? " << r << " " << l << endl;
		fflush(stdout);
		cin >> an;
		if (an == "e") return 0;
		if (an == "y") {
			cout << "! " << r << endl;
		} else 	cout << "! " << l << endl;
		fflush(stdout);
	}
	//system("pause");
	return 0;
}