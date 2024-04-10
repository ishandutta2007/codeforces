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
	int n = st.size();
	deque<char> a;
	a.push_back(st[0]);
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (!a.empty() && st[i] == a.back()) {
			a.pop_back();
			cnt++;
		}
		else {
			a.push_back(st[i]);
		}
	}
	if (cnt % 2 == 0) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}
	//system("pause");
	return 0;
}