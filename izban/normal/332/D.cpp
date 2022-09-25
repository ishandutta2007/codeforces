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

const int maxn = 1 << 11;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;
int a[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll sum = 0;
	while (cin >> n >> k) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			a[i][i] = -1;
			for (int j = i + 1; j < n; j++) {
				scanf("%d", &a[i][j]); 
				if (a[i][j] != -1) sum += 2 * a[i][j];
				a[j][i] = a[i][j];
			}
		}
		if (k != 2) {
			cout << sum / n << endl;
		} else {
			sum = 0;
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				ll csum = 0;
				int ccnt = 0;
				for (int j = 0; j < n; j++) ccnt += a[i][j] != -1;
				for (int j = 0; j < n; j++) if (a[i][j] != -1) csum += 1LL * a[i][j] * (ccnt - 1);
				sum += csum;
				cnt += ccnt * (ccnt - 1) / 2;
			}
			cout << sum / cnt << endl;
		}
	}

	return 0;
}