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


const int maxn = 1 << 7;

int n, m;
int c[maxn], r[maxn], ck[maxn], rk[maxn];
int a[maxn][maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			c[j] += a[i][j];
			r[i] += a[i][j];
		}

	while (1) {
		bool f(false);
		for (int i = 0; i < n; i++) {
			if (r[i] < 0) {
				r[i] *= -1;
				rk[i] ^= 1;
				for (int j = 0; j < m; j++) {
					a[i][j] *= -1;
					c[j] += 2 * a[i][j];
				}
				f = true;
			}
		}

		for (int j = 0; j < m; j++) {
			if (c[j] < 0) {
				c[j] *= -1;
				ck[j] ^= 1;
				for (int i = 0; i < n; i++) {
					a[i][j] *= -1;
					r[i] += 2 * a[i][j];
				}
				f = true;
			}
		}
		if (!f) break;
	}
	
	vector<int> rans, cans;
	for (int i = 0; i < n; i++) if (rk[i]) rans.push_back(i+1);
	for (int j = 0; j < m; j++) if (ck[j]) cans.push_back(j+1);

	cout << rans.size() << " ";
	for (int i = 0; i < rans.size(); i++)
		cout << rans[i] << " ";
	cout << endl;
	cout << cans.size() << " ";
	for (int j = 0; j < cans.size(); j++)
		cout << cans[j] << " ";
	cout << endl;

	return 0;
}