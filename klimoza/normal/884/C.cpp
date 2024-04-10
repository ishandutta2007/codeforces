#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")												
#pragma GCC optimize("rename-registers")									
#pragma GCC optimize("move-loop-invariants")								
#pragma GCC optimize("unswitch-loops")											
#pragma GCC optimize("function-sections")										
#pragma GCC optimize("data-sections")										
#pragma GCC optimize("branch-target-load-optimize")							
#pragma GCC optimize("branch-target-load-optimize2") 						
#pragma GCC optimize("btr-bb-exclusive")
#pragma comment(linker, "/stack:200000000")


#include <iostream>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;
double eps = 1e-7;

vector<int> p;
vector<ll> sz;

void make_dsu(int n) {
	p.resize(n);
	sz.resize(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}

int get_par(int v) {
	if (v == p[v]) return v;
	return p[v] = get_par(p[v]);
}

void merge(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if (sz[a] > sz[b]) swap(a, b);
	if (a == b) return;
	p[a] = b;
	sz[b] += sz[a];
}


int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	make_dsu(n);
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t; t--;
		merge(t, i);
	}
	ll sum = 0;
	ll maxi1 = -INF;
	ll maxi2 = -INF;
	vector<bool> used(n);
	for (int i = 0; i < n; i++) {
		int f = get_par(i);
		if (used[f]) continue;
		sum += sz[f] * sz[f];
		if (sz[f] > maxi1) {
			maxi2 = maxi1;
			maxi1 = sz[f];
		}
		else if (sz[f] > maxi2) {
			maxi2 = sz[f];
		}
		used[f] = true;
	}
	if (maxi2 == -INF) {
		cout << sum << endl;
	}
	else {
		sum -= maxi1 * maxi1;
		sum -= maxi2 * maxi2;
		sum += (maxi1 + maxi2) * (maxi1 + maxi2);
		cout << sum << endl;
	}
	//system("pause");
	return 0;
}