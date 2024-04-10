#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = 111;
const int inf = 1e9;

int n, k;
int a[maxn];
int b[maxn];
int fct[maxn];
double pr[6][1111];

int getnom(int *a) {
	int res = 0;
	for (int i = 0; i + 1 < n; i++) {
		int cnt = 0;
		for (int j = i + 1; j < n; j++) cnt += a[j] < a[i];
		res += cnt * fct[n - i - 1];
	}
	return res;
}

bool used[maxn];
void setnom(int k) {
	for (int i = 1; i <= n; i++) used[i] = 0;
	for (int i = 0; i < n; i++) {
		int o = k / fct[n - i - 1];
		k %= fct[n - i - 1];
		for (int j = 1; j <= n; j++) {
			if (!used[j]) {
				if (o == 0) {
					b[i] = j;
					used[j] = 1;
				}
				o--;
			}
		}
	}
}

int count(int *a) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			res += a[i] > a[j];
		}
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	fct[0] = 1;
	for (int i = 1; i < maxn; i++) fct[i] = fct[i - 1] * i;

	while (cin >> n >> k) {
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i < fct[n]; i++) for (int j = 0; j < 6; j++) pr[j][i] = 0;
		pr[0][getnom(a)] = 1.0;

		for (int it = 0; it < k; it++) {
			for (int i = 0; i < fct[n]; i++) {
				setnom(i);
				for (int l = 0; l < n; l++) {
					for (int r = l; r < n; r++) {
						for (int o = 0; l + o < r - o; o++) swap(b[l + o], b[r - o]);
						pr[it + 1][getnom(b)] += pr[it][i] / (n * (n + 1) / 2);
						for (int o = 0; l + o < r - o; o++) swap(b[l + o], b[r - o]);
					}
				}
			}
		}
		//d/ouble sum = 0;
		//for (int i = 0; i < fct[n]; i++) sum += pr[1][i];
		//cout << sum << endl;
		double ans = 0;
		for (int i = 0; i < fct[n]; i++) {
			setnom(i);
			ans += pr[k][i] * count(b);
		}
		printf("%.10lf\n", ans);
	}

	return 0;
}