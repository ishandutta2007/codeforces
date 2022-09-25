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
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 18;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, cans1, cans2;
int a[maxn];

void trysol(int x) {
	int N = n, M = m;
	int c1 = 0, c2 = 0;

	a[0] = x;
	if (x == 1)
		m--;
	else
		n--;
	for (int i = 1; i < N + M; i++) {
		if (i & 1) {
			if (a[i - 1] == 0) {
				if (m > 0) {
					m--;
					a[i] = 1;
				} else {
					n--;
					a[i] = 0;
				}
			} else {
				if (n > 0) {
					n--;
					a[i] = 0;
				} else {
					m--;
					a[i] = 1;
				}
			}				
		} else {
			if (a[i - 1] == 0) {
				if (n > 0) {
					n--;
					a[i] = 0;
				} else {
					m--;
					a[i] = 1;
				}
			} else {
				if (m > 0) {
					m--;
					a[i] = 1;
				} else {
					n--;
					a[i] = 0;
				}
			}
		}
	}
	for (int i = 0; i + 1 < N + M; i++) {
		c1 += a[i] == a[i + 1];
		c2 += a[i] != a[i + 1];
	}
	if (c1 > cans1)
		cans1 = c1, cans2 = c2;
	n = N; m = M;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> m) {
		cans1 = cans2 = -1;
		int c1 = 0, c2 = 0;
		int N = n, M = m;

		trysol(0);
		trysol(1);

		cout << cans1 << " " << cans2 << endl;
	}

	return 0;
}