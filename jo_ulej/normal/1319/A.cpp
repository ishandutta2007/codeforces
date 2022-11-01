#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <random>
#ifdef __LOCAL
#define DBG(X) cout << "[DBG] " << #X << ": " << (X) << '\n';
#else
#define DBG(X) 42;
#endif
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
const int INT_INT = (int)2e9;
const ll LL_INF = (ll)2e18;
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
	for(auto& el: vec) os << el << ' ';
	return os;
}
template<class T> T fetch() {
	T rez;
	cin >> rez;
	return rez;
}
void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
const int MAXN = (int)1e5 + 7;
int r[MAXN], b[MAXN], cnt10 = 0, cnt01 = 0;
int n;
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> r[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	for(int i = 0; i < n; ++i) {
		if(r[i] == 1 && b[i] == 0) ++cnt10;
		if(r[i] == 0 && b[i] == 1) ++cnt01;
	}
	if(cnt10 == 0) {
		cout << "-1\n";
	} else {
		int answ = (cnt01 / cnt10) + 1;
		cout << answ << '\n';
	}
}
int main() {
	fastIO();
	solve();
	return 0;
}