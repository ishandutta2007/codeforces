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

using namespace std;

int find(int a) {
	int ans = 0;
	while (a > 0) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}
signed main() {
	int a;
	cin >> a;
	while (find(a) % 4 != 0) {
		a++;
	}
	cout << a;
}