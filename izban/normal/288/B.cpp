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

int n, k;
int ans;
vector<int> p;

int fct(int x) {
	if (!x) return 1;
	return x * fct(x - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> k) {
		ans = 0;
		p.clear();

		for (int i = 0; i <= k; i++)
			p.push_back(1); p[0] = 0;

		int o = fct(k);
		//for (int it = 0; it < o; it++) {
		while (1) {
			bool f = 1;
			for (int i = 1; i <= k; i++) {
				bool f1 = 0;
				int x = i;
				for (int j = 0; j < 10; j++) {
					x = p[x];
					f1 |= x == 1;
				}
				f &= f1;
			}
			ans += f;
			//next_permutation(p.begin() + 1, p.end());
			int cur = k;
			p[cur]++;
			while (p[cur] == k + 1) {
				p[cur] = 1;
				cur--;
				p[cur]++;
			}
			if (!cur) break;
		}

		for (int i = k + 1; i <= n; i++)
			ans = 1LL * ans * (n - k) % mod;

		cout << ans << endl;
	}

	return 0;
}