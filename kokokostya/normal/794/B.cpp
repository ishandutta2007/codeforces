#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include<cmath>

using namespace std;
//#define LOCAL

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	long double h;
	cin >> n >> h;
	for (int i = 0; i < n - 1; i++) {
		cout << fixed << setprecision(9) << h * sqrt(i + 1) / sqrt(n) << ' ';
	}
	return 0;
}