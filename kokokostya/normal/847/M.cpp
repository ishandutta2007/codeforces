#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>
#include <deque>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;

//inline void operator delete (void *) {};

typedef long long ll;

const int MAX_N = 110;

int n;
int a[MAX_N];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int di = a[n - 1] - a[n - 2];
	for (int i = 1; i < n; i++) {
		if (di != a[i] - a[i - 1]) {
			cout << a[n - 1] << "\n";
			return 0;
		}
	}
	cout << a[n - 1] + a[n - 1] - a[n - 2] << "\n";
	return 0;
}