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

int n;
pair<int, ll> a[maxn];
ll b[32];
ll c[maxn];
double d[maxn];
bool f[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	//	scanf("%d", &n);
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			//scanf("%d%d", &a[i].first, &a[i].second);
			cin >> a[i].first >> a[i].second;
		sort(a, a + n);
		
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1].first - a[i].first >= 16) {
				a[i + 1].second++;
				continue;
			}
			ll o = 1 << (2 * (a[i + 1].first - a[i].first));
			ll ost = a[i].second - 1LL * a[i + 1].second * o; ost = max(ost, 0LL);
			if (ost) {
				if (o) {
					a[i + 1].second += ost / o;
					a[i + 1].second += ost % o > 0;
				} else {
					a[i + 1].second += 1;
				}
			}
		}
		int ans = 0;
		while ((1LL << (2 * (ans + 1))) < a[n - 1].second)
			ans++;
		cout << ans + a[n - 1].first + 1 << endl;
	}
	//for (int i = 0; i < 10000; i++)
	//	cout << (1LL << (2 * i)) << " " <<  i << endl;
	return 0;
}