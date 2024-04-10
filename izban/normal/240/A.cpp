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

using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")


const int maxn = 1 << 17;

int n, m, k, f[maxn], d[maxn], mn[maxn], mx[maxn];
int mxx = 0, mnn = maxn, canlose[maxn], canwin[maxn];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> m >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		f[x] = 1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cin >> d[i];
		int a1 = 0, a2 = 0, a3 = 0;
		for (int j = 0; j < d[i]; j++) {
			int x;
			cin >> x;
			if (x == 0)
				a3++;
			else
			if (f[x])
				a1++;
			else
				a2++;
		}
		mx[i] = a1 + min(k-a1, a3);
		mn[i] = a1 + max(0, a3 - (m-k - a2));
		mxx = max(mxx, mx[i]);
		mnn = min(mnn, mn[i]);
	}

	for (int i = 0; i < n; i++) {
		canwin[i] = 1;
		for (int j = 0; j < n; j++) {
			if (mn[i] < mx[j] && i != j)
				canlose[i] = 1;
			canwin[i] &= mx[i] >= mn[j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (canwin[i] && canlose[i])
			cout << "2\n";
		else if (canwin[i])
			cout << "0\n";
		else
			cout << "1\n";
	}

	return 0;
}