// Problem: F. Interesting Sections
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
template<class T>
struct fenwick_range_update
{
	int sz;
	vector<int> tr;

	void init(int _sz)
	{
		sz = _sz + 1;
		tr.resize(sz+1);
	}

	T query(int idx)
	{
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx))
			ans += tr[idx];
		return ans;
	}

	void update(int idx, T val)
	{
		if(idx <= 0) return;
		for(; idx <= sz; idx += (idx & -idx))
			tr[idx] += val;
	}

	void update(int l, int r, T val)
	{
		update(l, val);
		update(r + 1, -val);
	}
	void clear() {
		fill(all(tr), 0);
	}
};

template<class T>
struct fenwick
{
	int sz;
	fenwick_range_update<T> t0, t1;	
	
	fenwick(int _sz)
	{
		sz = _sz;
		t0.init(sz + 1);
		t1.init(sz + 1);
	}

	void update(int l, int r, T val)
	{
		l++,r++;
		t0.update(l, r, val);
		t1.update(l, r, -(l - 1) * val);
		t1.update(r + 1, sz, (r - l + 1) * val);
	}
	void clear() {
		t0.clear();t1.clear();
	}

	T query(int idx) { return (t0.query(idx) ? idx : 0) + t1.query(idx); }
	T query(int l, int r) { l++,r++;return query(r) - query(l - 1); }
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	vector<ll> a(n), pop(n);
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	for(int i = 0; i < n; i++) cin>>a[i];//a[i] = rng()%1000000000000000000;//cin >> a[i];
	for(int i = 0; i < n; i++) pop[i] = __builtin_popcountll(a[i]);
	ll ans = 0;//CHANGE BACK TO 60!!!!!! FUCKING RETARD
		 vector<int> st_min, st_max;
	const int C = 10;
	vector<fenwick<int>> smax(C, fenwick<int>(n+1)), smin(C, fenwick<int>(n+1));//
	for(int bits = 0; bits < 60; bits+=C) {
	    st_min.clear(),st_max.clear();
	ll AA = 0;for(auto &i : smax) i.clear();for(auto &i : smin) i.clear();
		 for(int i = 0; i < n; i++) {//
		 	// auto prv = [&](vector<int> &st) {
		 	// 	if(st.empty()) return 0;
		 	// 	else return st.back()+1;
		 	// };
		 	#define prv(st) (st.empty()?0:st.back()+1)
		 	while(st_min.size() && a[st_min.back()] > a[i]) {
		 		int v = st_min.back();
		 		int R = pop[st_min.back()]-bits;
		 		st_min.pop_back();
		 		if(R>=0&&R<C) {
		 			AA -= smax[R].query(prv(st_min), v);
		 			smin[R].update(prv(st_min), v, -1);
		 		}
		 	}
		 	if(pop[i]-bits < C && pop[i]-bits >= 0) {
		 		AA += smax[pop[i]-bits].query(prv(st_min), i);
		 		smin[pop[i]-bits].update(prv(st_min), i, 1);
		 	}
		 	st_min.push_back(i);
		 	
		 	while(st_max.size() && a[st_max.back()] < a[i]) {
		 		int v = st_max.back();
		 		int R = pop[st_max.back()] - bits;
		 		st_max.pop_back();
		 		if(R >= 0 && R < C) {
		 			AA -= smin[R].query(prv(st_max), v);
		 			smax[R].update(prv(st_max), v, -1);
		 		}
		 	}
		 	if(pop[i]-bits < C && pop[i]-bits >= 0) {
		 		AA += smin[pop[i]-bits].query(prv(st_max), i);
		 		smax[pop[i]-bits].update(prv(st_max), i, 1);
		 	}
		 	st_max.push_back(i);
		 	ans += AA;
		 }
	}
	cout << ans << '\n';
}