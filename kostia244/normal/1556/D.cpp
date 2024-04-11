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
const int local = 0;
vector<int> a = {0, 6, 9, 6};;
int qcnt = 0;
map<array<int, 3>, int> memo;
int ask(int tp, int i, int j) {
	if(i > j) swap(i, j);
	if(memo.count({tp, i, j})) return memo[{tp, i, j}];
	++qcnt;
	cout << (tp?"and":"or") << " " << i << " " << j << endl;
	if(!local) cin >> memo[{tp, i, j}];
	else memo[{tp, i, j}] = tp ? a[i]&a[j] : a[i]|a[j];
	return memo[{tp, i, j}];
}
int cmp(int i, int j) {
	int va0 = ask(0, i, 1), va1 = ask(1, i, 1);
	int vb0 = ask(0, j, 1), vb1 = ask(1, j, 1);
	auto get = [](int a, int b) { return (a>>b)&1; };
	for(int i = 30; i--;) {
		int va = get(va0, i)+get(va1, i);
		int vb = get(vb0, i)+get(vb1, i);
		if(va != vb) return va < vb;
	}
	return 0;
}
int solve(int v, int a, int b) {
	int va0 = ask(0, a, v), va1 = ask(1, a, v);
	int ab0 = ask(0, a, b), ab1 = ask(1, a, b);
	int vb0 = ask(0, b, v), vb1 = ask(1, b, v);
	auto get = [](int a, int b) { return (a>>b)&1; };
	int ans = 0;
	for(int i = 30; i--;) {
		int va = get(va0, i)+get(va1, i);
		int vb = get(vb0, i)+get(vb1, i);
		int ab = get(ab0, i)+get(ab1, i);
		int v = (va+vb-ab)/2; 
		ans |= v<<i;
	}
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, k;
	if(!local) cin >> n >> k;
	else n = a.size()-1, k = n;
	vector<int> srt(n-1);
	iota(all(srt), 2);
	sort(all(srt), cmp);
	//for(auto i : srt) cout << a[i] << ", "; cout << endl;
	vector<int> S;
	if(k == 1) {
		S = vector<int>{srt[0], srt[1], 1};
	} else {
		S = vector<int>{srt[k-2-(k==n)], srt[k-1-(k==n)], 1};
	}
	int ans = 0;
	//sort(all(a));
	//int intended = a[k];
	int v = solve(S[0], S[1], S[2]), a = solve(S[1], S[0], S[2]), b = solve(S[2], S[1], S[0]);
	S = {v, a, b};
	sort(all(S));
	if(k == n) ans = S.back();
	else if(k == 1) ans = S[0];
	else ans = S[1];
	// cout << v << endl;
	cout << "finish " << ans << endl; 
	assert(qcnt <= 2*n);
}