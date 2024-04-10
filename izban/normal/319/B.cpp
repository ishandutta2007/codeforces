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

int n, a[maxn];

bool reading() {
	if (!(cin >> n)) return 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	return 1;
}

int fastsolve() {
	vector<int> nxt(n, -1), alive(n, 1), q;
	for (int i = 0; i < n - 1; i++) nxt[i] = i + 1;
	for (int i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) q.push_back(i);

	int ans = 0;
	while (1) {
		if (!q.size()) break;
		for (int i = (int)q.size() - 1; i >= 0; i--) {
			alive[nxt[q[i]]] = 0;
			nxt[q[i]] = nxt[nxt[q[i]]];
		}
		vector<int> nq;
		for (int i = 0; i < (int)q.size(); i++) 
			if (alive[q[i]] && nxt[q[i]] != -1 && a[q[i]] > a[nxt[q[i]]]) 
				nq.push_back(q[i]);
		q = nq;
		ans++;
	}
	return ans;
}

int slowsolve() {
	vector<int> q;
	for (int i = 0; i < n; i++) q.push_back(a[i]);
	
	for (int ans = 0; ans < 1e9; ans++) {
		vector<int> nq;
		for (int i = 0; i < q.size(); i++) if (!i || q[i] >= q[i - 1]) nq.push_back(q[i]);
		if (q == nq) return ans;
		q = nq;
	}
}

void gen() {
	n = rand() % 5 + 1;
	for (int i = 0; i < n; i++) a[i] = i + 1;
	random_shuffle(a, a + n);
}

void stress() {
	for (int it = 0; it < 10000; it++) {
		gen();
		int ans1 = fastsolve();
		int ans2 = slowsolve();
		if (ans1 != ans2) {
			cout << n << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			cout << ans1 << " instead of " << ans2 << endl;
			cout << it << endl;
			break;
		}
		cerr << it << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	if (0) stress();

	while (reading()) cout << fastsolve() << endl;

	return 0;
}