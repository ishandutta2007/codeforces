#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
void add(int& x, int y) { if ((x += y) >= P) x -= P; }

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct F {
	ll x, y;
	F(ll x = 0, ll y = 1) : x(x), y(y) { ll g = gcd(x, y); this->x /= g; this->y /= g; }
	F operator+(const F& rhs) const { return F(x * rhs.y + y * rhs.x, y * rhs.y); }
	bool operator<(const F& rhs) const { return x * rhs.y < y * rhs.x; }
	bool operator>(const F& rhs) const { return x * rhs.y > y * rhs.x; }
};

const int _ = 200001;

int N;
int m[_], k[_];
pair<F, int> a[_];
pair<int, int> b[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> m[i] >> k[i];
	F mx = 0; vector<int> opt;
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j != _; ++j) a[j] = make_pair(F(0, 1), j);
		for (int j = 1; j <= N; ++j) if (k[j] >= i) a[m[j]].first = a[m[j]].first + F(1, 1);
		else a[m[j]].first = a[m[j]].first + F(k[j], i);
		nth_element(a + 1, a + i, a + _, greater<pair<F, int>>());
		F sum = 0;
		for (int j = 1; j <= i; ++j) sum = sum + a[j].first;
		if (mx < sum) {
			mx = sum;
			opt.clear();
			for (int j = 1; j <= i; ++j) opt.push_back(a[j].second);
		}
	}
	for (int i = 1; i != _; ++i) b[i].second = i;
	for (int i = 1; i <= N; ++i) b[m[i]].first += k[i];
	sort(b + 1, b + _, greater<pair<int, int>>());
	int pre = 0; F mx0 = 0; int op = 0;
	for (int i = 1; i <= N; ++i) {
		pre += b[i].first;
		if (i <= 20) continue;
		F cur(pre, i);
		if (mx0 < cur) {
			mx0 = cur;
			op = i;
		}
	}
	if (mx0 < mx) {
		// cerr << mx.x << "/" << mx.y << " T1\n";
		cout << opt.size() << '\n';
		for (int x : opt) cout << x << ' ';
	} else {
		// cerr << mx0.x << "/" << mx0.y << " T2\n";
		cout << op << '\n';
		for (int i = 1; i <= op; ++i) cout << b[i].second << ' ';
	}

	return 0;
}