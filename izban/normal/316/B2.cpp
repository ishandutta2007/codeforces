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

const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;

int n, x, p[maxn], nxt[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> x) {
		memset(p, 0, sizeof(p));
		memset(nxt, 0, sizeof(nxt));
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			nxt[p[i]] = i;
		}

		int add = -1;
		vector<int> v;
		for (int i = 1; i <= n; i++) if (!p[i]) {
			int cnt = 0, cur = i;
			int num = -1;
			while (cur) {
				if (cur == x) num = cnt;
				cnt++;
				cur = nxt[cur];
			}
			if (num == -1) v.push_back(cnt);
			else add = num;
		}

		vector<int> d(n + 1, 0);
		d[add] = 1;
		for (int i = 0; i < v.size(); i++) {
			for (int j = n; j >= 0; j--) 
				if (j + v[i] <= n && d[j] == 1) 
					d[j + v[i]] = 1;
		}
		for (int i = 0; i <= n; i++) if (d[i]) cout << i + 1 << endl;
		cout << endl;
	}

	return 0;
}