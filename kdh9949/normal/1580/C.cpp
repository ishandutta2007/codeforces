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
	vpii a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].y += a[i].x;
		a[i].x = a[i].y - a[i].x;
	}
	vint lst(n + 1, -1);
	struct Info { int s, e, i; };
	vector<Info> v;
	for(int i = 1; i <= m; i++) {
		ints(x, y);
		if(lst[y] > 0) {
			if(lst[y] < i) v.push_back({lst[y], i, y});
			lst[y] = -1;
		}
		else lst[y] = i + a[y].y - a[y].x;
	}
	for(int i = 1; i <= n; i++) if(0 < lst[i] && lst[i] < m + 1) v.push_back({lst[i], m + 1, i});
	
	vint sum(m + 2);
	const static int B = 200;
	vector<vint> bsum(B, vint(m + B + 2));
	for(Info &t : v) {
		pii c = a[t.i];
		if(c.y >= B || t.e - t.s <= 5 * B) {
			for(int i = t.s; i < t.e; i += c.y) {
				sum[i]++;
				sum[min(t.e, i + c.x)]--;
			}
		}
		else {
			int ee = t.s + (t.e - t.s) / c.y * c.y;
			while(ee < t.e) ee += c.y;
			for(int i = 0; i < c.x; i++) {
				bsum[c.y][t.s + i]++;
				if(ee - c.y + i >= t.e) ee -= c.y;
				bsum[c.y][ee + i]--;
			}
		}
	}
	for(int i = 1; i <= m; i++) sum[i] += sum[i - 1];
	for(int i = 2; i < B; i++) {
		for(int j = 1; j <= m; j++) {
			if(i <= j) bsum[i][j] += bsum[i][j - i];
			sum[j] += bsum[i][j];
		}
	}
	
	for(int i = 1; i <= m; i++) cout << sum[i] << '\n';
	return 0;
}