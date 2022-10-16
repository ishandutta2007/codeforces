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


int used[101];

signed main() {
	int n;
	cin >> n;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		used[c]++;
		if (used[c] > ans) {
			ans = used[c];
		}
	}
	cout << ans;
}