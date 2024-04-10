#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ints(n, m);
	vector<string> b(n);
	for(string &s : b) cin >> s;
	
	vector<vint> num(n, vint(m));
	for(int i = 0, cnt = 0; i < n; i++) for(int j = 0; j < m; j++) num[i][j] = cnt++;
	
	const static int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
	
	vector<vint> e(n * m);
	for(int i = 1; i < n - 1; i++) {
		for(int j = 1; j < m - 1; j++) {
			if(b[i][j] == 'X') {
				int cnt = 0;
				for(int k = 0; k < 4; k++) cnt += (b[i + dx[k]][j + dy[k]] == '.');
				if(cnt & 1) {
					cout << "NO\n";
					return 0;
				}
				if(cnt == 4) {
					for(int k = 0; k < 4; k++) {
						int a = num[i + dx[k]][j + dy[k]];
						int b = num[i + dx[(k + 1) % 4]][j + dy[(k + 1) % 4]];
						e[a].push_back(b);
						e[b].push_back(a);
					}
				}
				else if(cnt == 2) {
					int aa = -1, bb;
					for(int k = 0; k < 4; k++) if(b[i + dx[k]][j + dy[k]] == '.') {
						if(aa < 0) aa = num[i + dx[k]][j + dy[k]];
						else bb = num[i + dx[k]][j + dy[k]];
					}
					e[aa].push_back(bb);
					e[bb].push_back(aa);
				}
			}
		}
	}
	
	vector<vint> ans(n, vint(m));
	const function<void(int, int)> ff = [&](int node, int col) {
		int x = node / m, y = node % m;
		if(ans[x][y]) return;
		ans[x][y] = col;
		for(int i : e[node]) ff(i, 5 - col);
	};
	
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(b[i][j] == '.') {
		if(ans[i][j]) continue;
		ff(num[i][j], 1);
	}
	
	cout << "YES\n";
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
		if(b[i][j] == '.') cout << ans[i][j] << " \n"[j == m - 1];
		else {
			int cur = 0;
			for(int k = 0; k < 4; k++) cur += ans[i + dx[k]][j + dy[k]];
			cout << cur << " \n"[j == m - 1];
		}
	}
	
	return 0;
}