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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int x[maxn], y[maxn];
double a[maxn];
double ans;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n) {
		ans = 10000000;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			a[i] = atan2(y[i]+0.0, x[i]+0.0);
		}
		sort(a, a + n);
		a[n] = a[0] + 2 * acos(-1.0);
		for (int i = 0; i < n; i++)
			ans = min(ans, fabs(2 * acos(-1.0) - fabs(a[i] - a[i + 1])));
		printf("%.10lf\n", ans / acos(-1.0) * 180.0);
	}

	return 0;
}