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

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

int n, r, c;
int ans, pans;
int p[maxn][21];
char buf[5 * maxn];
string s[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> r >> c) {
		ans = 0; pans = -1;
		scanf("%d%d%d\n", &n, &r, &c);
		for (int i = 0; i < n; i++) {
			scanf("%s", buf);
			s[i] = buf;
		}
		memset(p, 0, sizeof(p));
		for (int i = 0; i < c + 1; i++) s[n] += '.';

		int sum = 0, j = 0;
		for (int i = 0; i < n; i++) {
			while (j <= n && sum <= c) {
				sum += s[j].length() + 1*(j > i);
				j++;
			}
			p[i][0] = j - 1;
			sum -= s[i].length() + 1*(j > i + 1);
		}
		p[n][0] = n;

		for (int k = 1; k < 20; k++) {
			for (int i = 0; i <= n; i++) {
				p[i][k] = p[p[i][k - 1]][k - 1];
			}
		}

		for (int i = 0; i < n; i++) {
			int cur = i;
			for (int k = 0; k < 20; k++) {
				if (r & (1 << k)) {
					cur = p[cur][k];
				}
			}
			if (cur - i > ans) {
				ans = cur - i;
				pans = i;
			}
		}

		int cur = pans;
		for (int i = 0; i < r && cur < n; i++) {
			for (int j = cur; j < p[cur][0]; j++) cout << s[j] << " \n"[j == p[cur][0] - 1];
			cur = p[cur][0];
		}
	}

	return 0;
}