#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
using namespace std;
#define pb push_back;
#define po(x) 1<<x
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 1000000007
const ll INF = 10E16;
const ll mask = po(9) - 1;
struct pp {
	ll fi, sc;
	bool operator < (const pp b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
struct node {
	ll x, y, cost;
};
ll n, m,P[DIM];
vector < node> V;
bool mc(node a, node b) {
	return a.cost < b.cost;
}
ll F(ll x) {
	if (x == P[x])return x;
	return P[x] = F(P[x]);
}
void unite(ll x, ll y) {
	if (rand() % 2 == 0) {
		P[x] = y;
	}
	else {
		P[y] = x;
	}
}
int main() {
	schnell;
	cin >> n >> m;
	forn(i, n)P[i] = i;
	forn(i, m) {
		V.resize(V.size() + 1);
		cin >> V[i-1].x >>V[i-1].y >> V[i-1].cost;
		
	}
	node start = V[0];
	sort(V.begin(), V.end(), mc);
	for (node to : V) {
		if (to.x == start.x && to.y == start.y && to.cost == start.cost)continue;
		ll x = F(to.x), y = F(to.y), c = to.cost;
		ll x2 = F(start.x), y2 = F(start.y);
		if (x > y)swap(x, y);
		if (x2 > y2)swap(x, y);
		if (x == x2 && y == y2) {
			cout << c << endl;
			return 0;
		}
		unite(x, y);
	}
	cout << 1000000000 << endl;
	return 0;
}