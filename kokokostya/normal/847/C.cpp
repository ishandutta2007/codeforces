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

const int MAX_N = 1e5 + 10;

long long n, k;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	long long sum = 0;
	long long cnt = 0;
	while (sum + cnt <= k && cnt < n) {
		sum += cnt;
		cnt++;
	}
	if (cnt == n && sum < k) {
		cout << "Impossible\n";
		return 0;
	}
	long long r = k - sum;
	for (int i = 0; i < cnt; i++) {
		if (i == r && r != 0) {
			cout << "()";
			n--;
		}
		cout << "(";
	}
	for (int i = 0; i < cnt; i++) {
		cout << ")";
	}
	while (cnt != n) {
		cout << "()";
		cnt++;
	}
	cout << "\n";
	return 0;
}