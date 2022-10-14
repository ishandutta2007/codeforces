#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 32e5 + 5;
int tr[maxn][2], sz = 1;
void add(int a) {
	int cur = 0;
	for(int d = 29; d>=0; d--) {
		if(!tr[cur][(a>>d)&1]) tr[cur][(a>>d)&1] = sz++;
		cur = tr[cur][(a>>d)&1];
	}
}
ll dfs(ll cur, ll d = 29) {
	if(d<0) return 0;
	if(tr[cur][0]&&tr[cur][1]) {
		return min(dfs(tr[cur][0], d-1), dfs(tr[cur][1], d-1)) + (1<<d);
	} else if(tr[cur][0]) {
		return dfs(tr[cur][0], d-1);
	}
	return dfs(tr[cur][1], d-1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vi a;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i, add(i);
	cout << dfs(0);
}