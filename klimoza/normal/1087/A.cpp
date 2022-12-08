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
	vector<char> a(n);
	for (int i = (n - 1) / 2 + 1; i < n; i++) {
		a[(i - 1 - (n - 1) / 2) * 2 + 1] = st[i];
	}
	for (int i = (n - 1) / 2; i >= 0; i--) {
		//cout << (-i + n / 2) * 2 << endl;
		a[((n - 1) / 2 - i) * 2] = st[i];
	}
	for (char c : a) cout << c;
	//system("pause");
	return 0;
}