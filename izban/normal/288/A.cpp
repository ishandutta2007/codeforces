#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> k) {
		if (k > n) {
			cout << "-1" << endl;
			continue;
		}

		if (k == 1) {
			if (n > 1) {
				cout << -1 << endl;
				return 0;
			}
			for (int i = 0; i < n; i++)
				cout << "a";
			cout << endl;
			continue;
		}

		cout << "ab";
		int j = 2;
		while (1) {
			if (n - j == k - 2) {
				for (int i = 2; i < k; i++)
					cout << (char)(i + 'a');
				cout << endl;
				break;
			}
			cout << (char)('a' + (j % 2));
			j++;
		}
	}

	return 0;
}