#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, m, p[N], pl, dis[N];
vector<int> G[N], fG[N];

int main() {
	scanf("%d%d", &n, &m);
	fill(dis + 1, dis + n + 1, -1);
	for(int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v); fG[v].pb(u);
	}
	scanf("%d", &pl);
	for(int i = 1; i <= pl; i ++) scanf("%d", p + i);
	queue<int> q; q.push(p[pl]); dis[p[pl]] = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int v : fG[u]) if(-1 == dis[v]) {
			q.push(v); dis[v] = dis[u] + 1;
		}
	}
	int Min = 0, Max = 0;
	for(int i = 1; i < pl; i ++) {
		bool out = 0, in = 0; int u = p[i];
		for(int v : G[u]) if(dis[v] == dis[u] - 1) {
			if(v != p[i + 1]) {
				out = 1;
			} else {
				in = 1;
			}
		}
		if(!in) Min ++; 
	}
	for(int i = 1; i < pl; i ++) {
		bool out = 0, in = 0; int u = p[i];
		for(int v : G[u]) if(dis[v] == dis[u] - 1) {
			if(v != p[i + 1]) {
				out = 1;
			} else {
				in = 1;
			}
		}
		if(out) Max ++;
	}
	printf("%d %d\n", Min, Max);
	return 0;
}