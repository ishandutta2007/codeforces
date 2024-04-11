


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int INF = 1e9 + 7;
const int MX = 4e5 + 7;
int mx = 20;
vector<int> pr(MX, -1);
vector< vector<int> > up(MX, vector<int>(mx, -1));
vector< vector<int> > val(MX, vector<int>(mx, INF));
int w[MX];


void get_up(int v) {
	up[v][0] = pr[v];
	val[v][0] = w[pr[v]];
	for (int i = 1; i < mx; i++) {
		int to = up[v][i - 1];
		if (to != -1) {
			up[v][i] = up[to][i - 1];
			val[v][i] = max(val[v][i - 1], val[to][i - 1]);
		}
	}
}

int get_p(int v) {
	int now = v;
	for (int i = mx - 1; i >= 0; i--) {
		if (up[now][i] != -1 && val[now][i] < w[v])
			now = up[now][i];
	}
	return pr[now];
}

vector<int> nw_p(MX, -1);
vector< vector<int> > nw_up(MX, vector<int>(mx, -1));
vector< vector<long long> > nw_val(MX, vector<long long>(mx, INF));

void get_nw_up(int v) {
	nw_up[v][0] = nw_p[v];
	nw_val[v][0] = w[nw_p[v]];
	for (int i = 1; i < mx; i++) {
		int to = nw_up[v][i - 1];
		if (to != -1) {
			nw_up[v][i] = nw_up[to][i - 1];
			nw_val[v][i] = nw_val[v][i - 1] + nw_val[to][i - 1];
		}
	}
}

int get_res(int v, long long X) {
	if (w[v] > X)
		return 0;
	int res = 1;
	X -= w[v];
	int now = v;
	for (int i = mx - 1; i >= 0; i--) {
		if (nw_up[now][i] != -1 && nw_val[now][i] <= X) {
			res += (1 << i);
			X -= nw_val[now][i];
			now = nw_up[now][i];
		}
	}
	return res;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q;
	cin >> q;
	int lst = 0;
	int cnt = 1;
	while (q--) {
		int tp;
		long long p, q;
		cin >> tp >> p >> q;
		if (tp == 1) {
			int r = p ^ lst;
			r--;
			long long W = q ^ lst;
			pr[cnt] = r;
			w[cnt] = W;
			get_up(cnt);

			nw_p[cnt] = get_p(cnt);
			get_nw_up(cnt);

			cnt++;
		}
		else {
			int r = p ^ lst;
			r--;
			long long X = q ^ lst;
			lst = get_res(r, X);
			cout << lst << '\n';

		}
	}
	return 0;
}