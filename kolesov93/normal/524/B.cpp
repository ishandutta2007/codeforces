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

struct Tp {
	int w, h;
} a[1111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n, h1 = 0, w1 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].w, &a[i].h);

		w1 += a[i].h;
		h1 = max(a[i].w, h1);
	}

	LL ans = LL(w1) * h1;
	for (int i = 0; i < n; ++i) {
		int H = a[i].h;
		bool fail = 0;
		int sw = 0, sh = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j].h > H && a[j].w > H) {
				fail = 1;
				break;
			} else
			if (a[j].h > H) {
				sh = max(sh, a[j].w);
				sw += a[j].h;
			} else
			if (a[j].w > H) {
			    sh = max(sh, a[j].h);
			    sw += a[j].w;
			} else {
				sh = max(sh, max(a[j].h, a[j].w) );
				sw += min(a[j].h, a[j].w);
			}
		}
		if (fail) continue;
		ans = min(LL(sw) * sh, ans);
	}
	for (int i = 0; i < n; ++i) {
		int H = a[i].w;
		bool fail = 0;
		int sw = 0, sh = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j].h > H && a[j].w > H) {
				fail = 1;
				break;
			} else
			if (a[j].h > H) {
				sh = max(sh, a[j].w);
				sw += a[j].h;
			} else
			if (a[j].w > H) {
			    sh = max(sh, a[j].h);
			    sw += a[j].w;
			} else {
				sh = max(sh, max(a[j].h, a[j].w) );
				sw += min(a[j].h, a[j].w);
			}
		}
		if (fail) continue;
		ans = min(LL(sw) * sh, ans);
	}
	cout << ans << endl;
    
    return 0;
}