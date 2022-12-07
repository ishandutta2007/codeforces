#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


const int N = 222222;
int n, m;
char s[N];
char t[N];
int si[N], ti[N];
int p[N];
int last[255];
int lst[N][27];
int go[27];

bool eq(int x, int y, int p) {
	if (y > p) y = -1;
	if (x > p) x = -1;
	return x == y;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
		
	scanf("%d%d\n", &n, &m);   	
	gets(s);
	gets(t);

	memset(last, -1, sizeof(last));
	for (int i = 0; i < n; ++i) {
		si[i] = (last[s[i]] == -1) ? -1 : (i - last[s[i]]);
		last[s[i]] = i;
	}

	memset(last, -1, sizeof(last));
	for (int i = 0; i < m; ++i) {
		ti[i] = (last[t[i]] == -1) ? -1 : (i - last[t[i]]);
		last[t[i]] = i;
	}

	memset(lst[n], -1, sizeof(lst[n]));
	for (int i = n - 1; i >= 0; --i) {
		memcpy(lst[i], lst[i + 1], sizeof(lst[i]));
		lst[i][s[i] - 'a'] = i;
	}


	p[0] = 0;
	for (int i = 1; i < m; ++i) {
		int& k = p[i] = p[i - 1];
		while (k && !eq(ti[k], ti[i], k) ) k = p[k - 1];
		if (eq(ti[k], ti[i], k)) ++k;else k = 0;
	}

	vector<int> ans;

	int k = 0;
	for (int i = 0; i < n; ++i) {
		while (k && !eq(ti[k], si[i], k) ) k = p[k - 1];
		if (eq(ti[k], si[i], k)) ++k;else k = 0;

		if (k == m) {			
			int offset = i - m + 1;

			int fail = 0;
			memset(go, -1, sizeof(go));

			for (int i = 0; i < 26; ++i) {
				int p = lst[offset][i];
				if (p != -1 && p - offset < m) {
					int from = s[p] - 'a';
					int to = t[p - offset] - 'a';

					if (go[from] == -1 && go[to] == -1) {
						go[from] = to;
						go[to] = from;
					} else
					if (go[from] == -1 || go[to] == -1) {
						fail = 1;
						break;
					} else {
						if (go[from] != to || go[to] != from) {
							fail = 1;
							break;
						}
					}
				}
			}
			if (!fail) ans.push_back(offset);
		}
	}

	printf("%d\n", ans.size());
	for (int i= 0; i < ans.size(); ++i) {
		printf("%d ", ans[i] + 1);
	}
	puts("");

    
    return 0;
}