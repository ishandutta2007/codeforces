#define  _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
#else
#endif
}
 
const int N = 8, LIMIT_QUERIES = 130 + 1;
int curY = 0, cnt = 0;
string Move(int x, int y) {
	assert(++cnt <= LIMIT_QUERIES);
	cout << x << ' ' << y << endl;
	curY = y;
	string s;
	cin >> s;
	return s;
}
 
bool scanRow(int row) {
	string s;
	if (curY == 8) {
		for (int y = 7; y > 0; y--) {
			s = Move(row, y);
			if (s == "Done")
				return true;
			if (s.find("Up") != string::npos)
				return scanRow(row);
			if (s.find("Down") != string::npos)
				return false;
		}
		return false;
	}
	for (int y = (curY == 1 ? 2 : 1); y <= N; y++) {
		s = Move(row, y);
		if (s == "Done")
			return true;
		if (s.find("Up") != string::npos)
			return scanRow(row);
		if (s.find("Down") != string::npos)
			return false;
	}
	return false;
}
 
bool solve() {
	curY = 1, cnt = 0;
	string s;
	for (int row = 1; row <= N; row++) {
		s = Move(row, curY);
		if (s == "Done")
			return true;
		if (scanRow(row))
			return true;
	}
	return false;
}
 
int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		bool b = solve();
		assert(b);
	}
}