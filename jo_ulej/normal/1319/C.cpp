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
#define len(X) ((int)X.size())
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
const int INT_INT = (int)2e9;
const ll LL_INF = (ll)2e18;
const int NIL = -1;
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
void solve() {
	int n = fetch<int>();
	auto S = fetch<string>();
	int answ = 0;
	for(char ch = 'z'; ch > 'a'; --ch) {
		while(true) {
			int pos = NIL;
			char prv = ch - 1;
			for(int i = 0; i < len(S); ++i) {
				if(S[i] != ch) continue;
				if(i != 0 && S[i - 1] == prv) {
					pos = i;
					break;
				}
				if(i != len(S)-1 && S[i + 1] == prv) {
					pos = i;
					break;
				}
			}
			if(pos == NIL) break;
			DBG(S); DBG(pos);
			++answ;
			S.erase(S.begin() + pos);
		}
	}
	cout << answ << '\n';
}
int main() {
	fastIO();
	solve();
	return 0;
}