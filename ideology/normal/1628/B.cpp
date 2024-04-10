#include <cmath>
#include <cstring>

#include <algorithm>
#include <chrono>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

typedef unsigned long long ull;

using namespace std;

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
int reduce(int x) { return x < 0 ? x + P : x; }
int neg(int x) { return x ? P - x : 0; }
void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int _ = 100005;

string s[_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; ++i) cin >> s[i];
		bool f = false;
		set<string> s2, s3;
		for (int i = 1; i <= N; ++i)
			if (s[i].length() == 1) f = true;
			else if (s[i].length() == 2) {
				s2.insert(s[i]);
				string rev;
				rev += s[i][1]; rev += s[i][0];
				if (s2.count(rev)) f = true;
			} else if (s[i].length() == 3) {
				s3.insert(s[i]);
				string rev;
				rev += s[i][2]; rev += s[i][1];
				if (s2.count(rev)) f = true;
				rev += s[i][0];
				if (s3.count(rev)) f = true;
			}
		s2.clear();
		for (int i = N; i; --i)
			if (s[i].length() == 2)
				s2.insert(s[i]);
			else if (s[i].length() == 3) {
				string rev;
				rev += s[i][1]; rev += s[i][0];
				if (s2.count(rev)) f = true;
			}
		cout << (f ? "YES\n" : "NO\n");
	}

	return 0;
}