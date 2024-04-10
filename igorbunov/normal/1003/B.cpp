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
#include <exception>
#include <stdexcept>

#define int long long

using namespace std;

signed main() {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> ans;
	if (a > b) {
		bool d = 1;
		ans.push_back(0);
		a--;
		int now = 0;
		while (now != c) {
			if (d) {
				ans.push_back(1);
				b--;
				now++;
			} else {
				ans.push_back(0);
				now++;
				a--;
			}
			d = !d;
		}
	} else {
		bool d = 0;
		ans.push_back(1);
		b--;
		int now = 0;
		while (now != c) {
			if (d) {
				ans.push_back(1);
				b--;
				now++;
			} else {
				ans.push_back(0);
				now++;
				a--;
			}
			d = !d;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (ans[i]) {
			for (int j = 0; j < b; j++) {
				cout << 1;
			}
			b = 0;
		} else {
			for (int j = 0; j < a; j++) {
				cout << 0;
			}
			a = 0;
		}
	}
}