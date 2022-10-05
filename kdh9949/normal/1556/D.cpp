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
	//ios::sync_with_stdio(0); cin.tie(0);

	ints(n, k);
	
	vll a(n + 1);
	for(int i = 2; i <= n; i++) {
		cout << "or 1 " << i << endl;
		lls(x);
		cout << "and 1 " << i << endl;
		lls(y);
		a[i] = x + y;
	}
	cout << "or 2 3" << endl;
	lls(x);
	cout << "and 2 3" << endl;
	lls(y);
	a[1] = (a[2] + a[3] - x - y) / 2;
	for(int i = 2; i <= n; i++) a[i] -= a[1];
	
	sort(1 + all(a));
	cout << "finish " << a[k] << endl;
	return 0;
}