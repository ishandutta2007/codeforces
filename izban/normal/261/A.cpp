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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
int a[maxn], Q[maxn], q;

/*bool f(int x) {
	int i = 0, res = 0;
	while (i < n) {
		int k = 0;
		while (k < q && i < n) {
			ans 
		}
	}
}*/

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	//scanf("%d", &m);
	while (cin >> m) {
		for (int i = 0; i < m; i++)
			scanf("%d", &Q[i]);
		sort(Q, Q + m);
		//reverse(q, q + m);
		q = Q[0];
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		reverse(a, a + n);

		int k = 0, ans = 0;
		while (k < n) {
			int j = 0;
			while (j < q && k < n) {
				ans += a[k];
				j++; k++;
			}
			j = 0;
			while (j < 2 && k < n) {
				j++; k++;
			}
		}
		cout << ans << endl;
		/*int l = 0, r = 1e9;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (f(m)) r = m;
			else l = m;
		}
		int ans = f(l) ? l : r;
		cout << ans << endl;*/
	}

	return 0;
}