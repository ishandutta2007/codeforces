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
const int INT_INF = (int)2e9;
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
const int MAXN = (int)3e5 + 7;
vector<int> G[MAXN], revG[MAXN];
int n, m, k, path[MAXN];
int dist[MAXN], Q[MAXN], head;
void BFS(int src) {
	for(int v = 0; v < n; ++v) dist[v] = INT_INF;
	dist[src] = 0;
	head = 0;
	Q[head++] = src;
	for(int j = 0; j < head; ++j) {
		int v = Q[j];
		for(auto& u: revG[v]) {
			if(dist[u]>dist[v]+1) {
				dist[u] = dist[v]+1;
				Q[head++] = u;
			}
		}
	}
}
void solve() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
		revG[u].emplace_back(v);
	}
	cin >> k;
	for(int i = 0; i < k; ++i) path[i] = fetch<int>() - 1;
	BFS(path[k - 1]);
	int mn = 0, mx = 0;
	for(int i = 0; i < k - 1; ++i) {
		int v = path[i], u = path[i + 1];
		if(dist[u] != dist[v] - 1) ++mn;
		int flag = 0;
		for(auto& u2: G[v]) {
			if(u2 != u && dist[u2] == dist[v] - 1) {
				flag = 1;
				break;
			}
		}
		mx += flag;
	}
	cout << mn << ' ' << mx << '\n';
}
int main() {
	fastIO();
	solve();
	return 0;
}