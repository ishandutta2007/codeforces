#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll
//using namespace __gnu_pbds;
using namespace std;
int n, m, i, v;
vi tree, a;
//n&1 => xor
//else or
void build(int v, int s, int e, bool x) {
	if(s == e)
		tree[v] = a[s-1];
	else {
		int mid = (s + e) / 2;
		build(2*v, s, mid, x^1);
		build(2*v+1, mid+1, e, x^1);
		if(x) {
			tree[v] = tree[2*v]^tree[2*v+1];
		} else {
			tree[v] = tree[2*v]|tree[2*v+1];
		}
	}
}

void upd(int i, int val, int v, int s, int e, bool x) {
	if(s == e)
		tree[v] = val;
	else {
		int mid = (s + e) / 2;
		if(i <= mid)
			upd(i, val, 2*v, s, mid, !x);
		else
			upd(i, val, 2*v+1, mid+1, e, !x);
		if(x) {
			tree[v] = tree[2*v]^tree[2*v+1];
		} else {
			tree[v] = tree[2*v]|tree[2*v+1];
		}
	}
//	cout << v << " " << i << " " << val << " " << s << " " << e << " " << tree[v] << "\n";
}


int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> n >> m;
	a.resize(1<<n);
	for(auto& i : a) cin >> i;
	tree.resize(4 * (1<<n));
	build(1, 1, 1<<n, 1^(n&1));
	while(m--) {
		cin >> i >> v;
		upd(i, v, 1, 1, 1<<n, 1^(n&1));
		cout << tree[1] << "\n";
	}
}