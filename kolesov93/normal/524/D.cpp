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
#include <stack>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 22222;
pair<int, int> e[N*2];
int deadtime[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n, M, T, en = 0;
	scanf("%d%d%d", &n, &M, &T);   	 
	for (int i = 0; i < n; ++i) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int x = ((h * 60) + m) * 60 + s;
		e[en++] = {x, (i + 1)};
		e[en++] = {x + T, -(i + 1)};
	}

	sort(e, e + en);
	int active = 0;
	int maxactive = 0;
	int uid = 0;
	int ilast = 0;
	vector<int> ans;

	for (int i = 0; i < en; ++i) {
		int id = abs(e[i].second) - 1;

		if (e[i].second > 0) {
			if (active < M) {
				ans.push_back(++uid);
				ilast = uid;
				deadtime[uid] = e[i].first + T;
				++active;
			} else {	
				int t = ilast;
				ans.push_back(t);
				deadtime[t] = e[i].first + T;
			}
		} else {
			if (e[i].first == deadtime[ans[id]]) {
				deadtime[ans[id]] = -1;
				--active;
			}
		}
		maxactive = max(maxactive, active);
	}
	
	if (maxactive == M) {
		printf("%d\n", uid);
		for (int i = 0; i < n; ++i) {
			printf("%d\n", ans[i]);
		}
	} else {
		printf("No solution\n");
	}
    
    return 0;
}