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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1e7 + 100;;
const int inf = 1000000007;
const int mod = 1000000007;


bool prime[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < maxn; i++) prime[i] = 1;
	for (int i = 2; i * i <= 1e7; i++) if (prime[i]) {
		if (1LL * i * i < maxn) 
			for (int j = i * i; j < maxn; j += i)
				prime[j] = false;
	}

	int n;
	while (cin >> n) {
		int cnt = 0;
		for (int i = 2; i < maxn; i++) {
			if (cnt == n) break;
			if (prime[i]) {
				cout << i << " ";
				cnt++;
			}
		}
		assert(cnt == n);
		cout << endl;
	}

	return 0;
}