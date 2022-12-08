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
	string st;
	cin >> st;
	int cnt1 = 0;
	int cnt2 = 0;
	for (char c : st) {
		if (c == '0') {
			cout << 3 << " " << 1 + cnt1 << endl;
			cnt1++;
			cnt1 %= 4;
		}
		else {
			if (!cnt2) cnt2 = 1;
			else cnt2 = 3;
			cout << 1 << " " << cnt2 << endl;
			if (cnt2 == 3) cnt2 = 0;
		}
	}
	//system("pause");
	return 0;
}